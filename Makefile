RELEASE=6.0

PACKAGE=ceph
VER=14.2.1
DEBREL=pve2

SRCDIR=ceph
BUILDSRC=${SRCDIR}-${VER}

ARCH:=$(shell dpkg-architecture -qDEB_BUILD_ARCH)
GITVERSION:=$(shell git rev-parse HEAD)

DBG_DEBS=ceph-common-dbg_${VER}-${DEBREL}_${ARCH}.deb \
ceph-fuse-dbg_${VER}-${DEBREL}_${ARCH}.deb \
ceph-mds-dbg_${VER}-${DEBREL}_${ARCH}.deb \
ceph-mgr-dbg_${VER}-${DEBREL}_${ARCH}.deb \
ceph-mon-dbg_${VER}-${DEBREL}_${ARCH}.deb \
ceph-osd-dbg_${VER}-${DEBREL}_${ARCH}.deb \
ceph-test-dbg_${VER}-${DEBREL}_${ARCH}.deb \
libcephfs2-dbg_${VER}-${DEBREL}_${ARCH}.deb \
librados2-dbg_${VER}-${DEBREL}_${ARCH}.deb \
libradosstriper1-dbg_${VER}-${DEBREL}_${ARCH}.deb \
librbd1-dbg_${VER}-${DEBREL}_${ARCH}.deb \
librgw2-dbg_${VER}-${DEBREL}_${ARCH}.deb \
radosgw-dbg_${VER}-${DEBREL}_${ARCH}.deb \
rbd-fuse-dbg_${VER}-${DEBREL}_${ARCH}.deb \
rbd-mirror-dbg_${VER}-${DEBREL}_${ARCH}.deb \
rbd-nbd-dbg_${VER}-${DEBREL}_${ARCH}.deb

MAIN_DEB=ceph_${VER}-${DEBREL}_${ARCH}.deb
DEBS_REST=ceph-base_${VER}-${DEBREL}_${ARCH}.deb \
ceph-common_${VER}-${DEBREL}_${ARCH}.deb \
ceph-fuse_${VER}-${DEBREL}_${ARCH}.deb \
ceph-mds_${VER}-${DEBREL}_${ARCH}.deb \
ceph-mgr_${VER}-${DEBREL}_${ARCH}.deb \
ceph-mon_${VER}-${DEBREL}_${ARCH}.deb \
ceph-osd_${VER}-${DEBREL}_${ARCH}.deb \
ceph-resource-agents_${VER}-${DEBREL}_${ARCH}.deb \
ceph-test_${VER}-${DEBREL}_${ARCH}.deb \
libcephfs2_${VER}-${DEBREL}_${ARCH}.deb \
libcephfs-dev_${VER}-${DEBREL}_${ARCH}.deb \
libcephfs-java_${VER}-${DEBREL}_all.deb \
libcephfs-jni_${VER}-${DEBREL}_${ARCH}.deb \
librados2_${VER}-${DEBREL}_${ARCH}.deb \
librados-dev_${VER}-${DEBREL}_${ARCH}.deb \
libradosstriper1_${VER}-${DEBREL}_${ARCH}.deb \
libradosstriper-dev_${VER}-${DEBREL}_${ARCH}.deb \
librbd1_${VER}-${DEBREL}_${ARCH}.deb \
librbd-dev_${VER}-${DEBREL}_${ARCH}.deb \
librgw2_${VER}-${DEBREL}_${ARCH}.deb \
librgw-dev_${VER}-${DEBREL}_${ARCH}.deb \
python3-ceph-argparse_${VER}-${DEBREL}_all.deb \
python3-cephfs_${VER}-${DEBREL}_${ARCH}.deb \
python3-rados_${VER}-${DEBREL}_${ARCH}.deb \
python3-rbd_${VER}-${DEBREL}_${ARCH}.deb \
python3-rgw_${VER}-${DEBREL}_${ARCH}.deb \
python-ceph_${VER}-${DEBREL}_${ARCH}.deb \
python-cephfs_${VER}-${DEBREL}_${ARCH}.deb \
python-rados_${VER}-${DEBREL}_${ARCH}.deb \
python-rbd_${VER}-${DEBREL}_${ARCH}.deb \
python-rgw_${VER}-${DEBREL}_${ARCH}.deb \
radosgw_${VER}-${DEBREL}_${ARCH}.deb \
rados-objclass-dev_${VER}-${DEBREL}_${ARCH}.deb \
rbd-fuse_${VER}-${DEBREL}_${ARCH}.deb \
rbd-mirror_${VER}-${DEBREL}_${ARCH}.deb \
rbd-nbd_${VER}-${DEBREL}_${ARCH}.deb
DEBS=$(MAIN_DEB) $(DEBS_REST)

DSC=ceph_${VER}-${DEBREL}.dsc

all: ${DEBS} ${DBG_DEBS}
	@echo ${DEBS}
	@echo ${DBG_DEBS}

${BUILDSRC}: ${SRCDIR} patches
	rm -rf $@
	mkdir $@.tmp
	rsync -ra ${SRCDIR}/ $@.tmp
	cd $@.tmp; ln -s ../patches patches
	cd $@.tmp; quilt push -a
	cd $@.tmp; rm -rf .pc ./patches
	echo "git clone git://git.proxmox.com/git/ceph.git\\ngit checkout ${GITVERSION}" >  $@.tmp/debian/SOURCE
	echo "debian/SOURCE" >> $@.tmp/debian/docs
	echo "${GITVERSION}\\nv${VER}" > $@.tmp/src/.git_version
	cp changelog.Debian $@.tmp/debian/changelog
	mv $@.tmp $@

.PHONY: deb
deb: ${DEBS} ${DBG_DEBS}
${DEBS_REST} ${DBG_DEBS}: $(MAIN_DEB)
$(MAIN_DEB): ${BUILDSRC}
	cd ${BUILDSRC}; dpkg-buildpackage -b -uc -us
	lintian ${DEBS}
	@echo ${DEBS}

.PHONY: dsc
dsc: ${DSC}
${DSC}: ${BUILDSRC}
	cd ${BUILDSRC}; dpkg-buildpackage -S -uc -us -d -nc
	@echo ${DSC}

.PHONY: download
download:
	# FIXME: better verification (download dsc and use dscverify with ceph.com release key?)
	dget --allow-unauthenticated --download-only 'https://download.ceph.com/debian-nautilus/pool/main/c/ceph/ceph_${VER}.orig.tar.gz'
	rm -rf ${SRCDIR}.tmp ${SRCDIR}
	mkdir ${SRCDIR}.tmp
	tar -C ${SRCDIR}.tmp --strip-components=1 -xf ceph_${VER}.orig.tar.gz
	# needed because boost and zstd builds fail otherwise
	find ${SRCDIR}.tmp -type f -name ".gitignore" -delete
	mv ${SRCDIR}.tmp/debian/changelog ${SRCDIR}.tmp/changelog.upstream
	mv ${SRCDIR}.tmp ${SRCDIR}

.PHONY: upload
upload: ${DEBS}
	tar cf - ${DEBS} | ssh repoman@repo.proxmox.com upload --product ceph-luminous --dist stretch --arch ${ARCH}

distclean: clean

.PHONY: clean
clean:
	rm -rf ${BUILDSRC} ${BUILDSRC}.tmp *_all.deb *_${ARCH}.deb *.changes *.dsc *.buildinfo *.tar.gz

.PHONY: dinstall
dinstall: ${DEB}
	dpkg -i ${DEB}
