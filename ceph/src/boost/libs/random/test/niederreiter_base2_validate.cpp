// Copyright Justinas Vygintas Daugmaudis, 2010-2018.
// Use, modification and distribution is subject to the
// Boost Software License, Version 1.0. (See accompanying
// file LICENSE-1.0 or http://www.boost.org/LICENSE-1.0)

#include <boost/random/niederreiter_base2.hpp>

#include <boost/utility.hpp>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "test_qrng_functions.hpp"

//
// DESCRIPTION:
// ~~~~~~~~~~~~
//
// This file tests the faure quasi-random number generator.
// These tests compare our results with values produced by the original
// version of ACM TOMS Algorithm 738, which  is available in the
// TOMS subdirectory in http://www.netlib.org
//
// For independently generated datasets look at http://people.sc.fsu.edu/~jburkardt/datasets/niederreiter2/


// Spatial dimension: 2
// N: 100
// Vectors skipped: 4095
static const double niederreiter_base2_02_100[100][2] =
{
  { 0.0003662109, 0.4705810548 },
  { 0.5003662111, 0.9705810549 },
  { 0.7503662111, 0.2205810547 },
  { 0.2503662110, 0.7205810549 },
  { 0.3753662110, 0.0955810547 },
  { 0.8753662111, 0.5955810548 },
  { 0.6253662111, 0.3455810548 },
  { 0.1253662110, 0.8455810549 },
  { 0.1878662110, 0.1580810547 },
  { 0.6878662111, 0.6580810548 },
  { 0.9378662112, 0.4080810548 },
  { 0.4378662110, 0.9080810549 },
  { 0.3128662110, 0.2830810548 },
  { 0.8128662111, 0.7830810549 },
  { 0.5628662111, 0.0330810547 },
  { 0.0628662110, 0.5330810548 },
  { 0.0941162110, 0.0018310547 },
  { 0.5941162111, 0.5018310548 },
  { 0.8441162111, 0.2518310547 },
  { 0.3441162110, 0.7518310549 },
  { 0.4691162110, 0.3768310548 },
  { 0.9691162112, 0.8768310549 },
  { 0.7191162111, 0.1268310547 },
  { 0.2191162110, 0.6268310548 },
  { 0.1566162110, 0.3143310548 },
  { 0.6566162111, 0.8143310549 },
  { 0.9066162111, 0.0643310547 },
  { 0.4066162110, 0.5643310548 },
  { 0.2816162110, 0.1893310547 },
  { 0.7816162111, 0.6893310548 },
  { 0.5316162111, 0.4393310548 },
  { 0.0316162109, 0.9393310549 },
  { 0.0472412109, 0.2362060547 },
  { 0.5472412111, 0.7362060549 },
  { 0.7972412111, 0.4862060548 },
  { 0.2972412110, 0.9862060549 },
  { 0.4222412110, 0.3612060548 },
  { 0.9222412112, 0.8612060549 },
  { 0.6722412111, 0.1112060547 },
  { 0.1722412110, 0.6112060548 },
  { 0.2347412110, 0.4237060548 },
  { 0.7347412111, 0.9237060549 },
  { 0.9847412112, 0.1737060547 },
  { 0.4847412111, 0.6737060548 },
  { 0.3597412110, 0.0487060547 },
  { 0.8597412111, 0.5487060548 },
  { 0.6097412111, 0.2987060548 },
  { 0.1097412110, 0.7987060549 },
  { 0.0784912110, 0.2674560547 },
  { 0.5784912111, 0.7674560549 },
  { 0.8284912111, 0.0174560547 },
  { 0.3284912110, 0.5174560548 },
  { 0.4534912110, 0.1424560547 },
  { 0.9534912112, 0.6424560548 },
  { 0.7034912111, 0.3924560548 },
  { 0.2034912110, 0.8924560549 },
  { 0.1409912110, 0.0799560547 },
  { 0.6409912111, 0.5799560548 },
  { 0.8909912111, 0.3299560548 },
  { 0.3909912110, 0.8299560549 },
  { 0.2659912110, 0.4549560548 },
  { 0.7659912111, 0.9549560549 },
  { 0.5159912111, 0.2049560547 },
  { 0.0159912109, 0.7049560549 },
  { 0.0238037109, 0.1190185547 },
  { 0.5238037111, 0.6190185548 },
  { 0.7738037111, 0.3690185548 },
  { 0.2738037110, 0.8690185549 },
  { 0.3988037110, 0.4940185548 },
  { 0.8988037111, 0.9940185549 },
  { 0.6488037111, 0.2440185547 },
  { 0.1488037110, 0.7440185549 },
  { 0.2113037110, 0.3065185548 },
  { 0.7113037111, 0.8065185549 },
  { 0.9613037112, 0.0565185547 },
  { 0.4613037110, 0.5565185548 },
  { 0.3363037110, 0.1815185547 },
  { 0.8363037111, 0.6815185548 },
  { 0.5863037111, 0.4315185548 },
  { 0.0863037110, 0.9315185549 },
  { 0.1175537110, 0.4002685548 },
  { 0.6175537111, 0.9002685549 },
  { 0.8675537111, 0.1502685547 },
  { 0.3675537110, 0.6502685548 },
  { 0.4925537111, 0.0252685547 },
  { 0.9925537112, 0.5252685548 },
  { 0.7425537111, 0.2752685548 },
  { 0.2425537110, 0.7752685549 },
  { 0.1800537110, 0.2127685547 },
  { 0.6800537111, 0.7127685549 },
  { 0.9300537112, 0.4627685548 },
  { 0.4300537110, 0.9627685549 },
  { 0.3050537110, 0.3377685548 },
  { 0.8050537111, 0.8377685549 },
  { 0.5550537111, 0.0877685547 },
  { 0.0550537110, 0.5877685548 },
  { 0.0394287109, 0.3533935548 },
  { 0.5394287111, 0.8533935549 },
  { 0.7894287111, 0.1033935547 },
  { 0.2894287110, 0.6033935548 }
};

// Spatial dimension: 7
// N: 100
// Vectors skipped: 4095
static const double niederreiter_base2_07_100[100][7] =
{
  { 0.0003662109, 0.4705810548, 0.6358642580, 0.9561767580, 0.6715087892, 0.9793701174, 0.6053466798 },
  { 0.5003662111, 0.9705810549, 0.3858642579, 0.0811767578, 0.2965087891, 0.0418701172, 0.4178466798 },
  { 0.7503662111, 0.2205810547, 0.9483642580, 0.8155517580, 0.5621337892, 0.9207763674, 0.5467529298 },
  { 0.2503662110, 0.7205810549, 0.1983642579, 0.1905517579, 0.4371337892, 0.1082763672, 0.4842529298 },
  { 0.3753662110, 0.0955810547, 0.2608642579, 0.7374267580, 0.7652587892, 0.8465576174, 0.6600341798 },
  { 0.8753662111, 0.5955810548, 0.5108642579, 0.3624267579, 0.1402587891, 0.1590576172, 0.3475341798 },
  { 0.6253662111, 0.3455810548, 0.0733642578, 0.5968017580, 0.9058837893, 0.7879638674, 0.7264404299 },
  { 0.1253662110, 0.8455810549, 0.8233642580, 0.4718017579, 0.0308837891, 0.2254638672, 0.2889404298 },
  { 0.1878662110, 0.1580810547, 0.1514892578, 0.2686767579, 0.3590087891, 0.7449951174, 0.9334716799 },
  { 0.6878662111, 0.6580810548, 0.9014892580, 0.6436767580, 0.7340087892, 0.3074951173, 0.1209716797 },
  { 0.9378662112, 0.4080810548, 0.4639892579, 0.3780517579, 0.4996337892, 0.6864013673, 0.9998779299 },
  { 0.4378662110, 0.9080810549, 0.7139892580, 0.5030517579, 0.6246337892, 0.3739013673, 0.0623779297 },
  { 0.3128662110, 0.2830810548, 0.7764892580, 0.0499267578, 0.2027587891, 0.6121826173, 0.8631591799 },
  { 0.8128662111, 0.7830810549, 0.0264892578, 0.9249267580, 0.8277587893, 0.4246826173, 0.1756591797 },
  { 0.5628662111, 0.0330810547, 0.5889892579, 0.1593017578, 0.0933837891, 0.5535888673, 0.8045654299 },
  { 0.0628662110, 0.5330810548, 0.3389892579, 0.7843017580, 0.9683837893, 0.4910888673, 0.2420654297 },
  { 0.0941162110, 0.0018310547, 0.9171142580, 0.5635986329, 0.4195556642, 0.3856201173, 0.3865966798 },
  { 0.5941162111, 0.5018310548, 0.1671142579, 0.4385986329, 0.5445556642, 0.5731201173, 0.5740966798 },
  { 0.8441162111, 0.2518310547, 0.7296142580, 0.7042236330, 0.3101806641, 0.4520263673, 0.4530029298 },
  { 0.3441162110, 0.7518310549, 0.4796142579, 0.3292236329, 0.6851806642, 0.5145263673, 0.5155029298 },
  { 0.4691162110, 0.3768310548, 0.0421142578, 0.8448486330, 0.0133056641, 0.2528076172, 0.3162841798 },
  { 0.9691162112, 0.8768310549, 0.7921142580, 0.2198486329, 0.8883056643, 0.6903076173, 0.6287841798 },
  { 0.7191162111, 0.1268310547, 0.3546142579, 0.9854736330, 0.1539306641, 0.3192138673, 0.2576904297 },
  { 0.2191162110, 0.6268310548, 0.6046142580, 0.1104736328, 0.7789306642, 0.6317138673, 0.6951904298 },
  { 0.1566162110, 0.3143310548, 0.4327392579, 0.1260986328, 0.6070556642, 0.1512451172, 0.0897216797 },
  { 0.6566162111, 0.8143310549, 0.6827392580, 0.7510986330, 0.4820556642, 0.8387451174, 0.9022216799 },
  { 0.9066162111, 0.0643310547, 0.2452392579, 0.0167236328, 0.7476806642, 0.2176513672, 0.0311279297 },
  { 0.4066162110, 0.5643310548, 0.9952392580, 0.8917236330, 0.3726806641, 0.7801513674, 0.9686279299 },
  { 0.2816162110, 0.1893310547, 0.5577392579, 0.4073486329, 0.9508056643, 0.0184326172, 0.1444091797 },
  { 0.7816162111, 0.6893310548, 0.3077392579, 0.5323486329, 0.0758056641, 0.9559326174, 0.8319091799 },
  { 0.5316162111, 0.4393310548, 0.8702392580, 0.2979736329, 0.8414306643, 0.0848388672, 0.2108154297 },
  { 0.0316162109, 0.9393310549, 0.1202392578, 0.6729736330, 0.2164306641, 0.8973388674, 0.7733154299 },
  { 0.0472412109, 0.2362060547, 0.4522705079, 0.1007080078, 0.0426025391, 0.7955322267, 0.4801025392 },
  { 0.5472412111, 0.7362060549, 0.7022705080, 0.9757080080, 0.9176025393, 0.2330322266, 0.5426025392 },
  { 0.7972412111, 0.4862060548, 0.1397705078, 0.2413330079, 0.1832275391, 0.8541259768, 0.4215087892 },
  { 0.2972412110, 0.9862060549, 0.8897705080, 0.8663330080, 0.8082275393, 0.1666259766, 0.6090087892 },
  { 0.4222412110, 0.3612060548, 0.5772705079, 0.3194580079, 0.3863525392, 0.9127197268, 0.2847900391 },
  { 0.9222412112, 0.8612060549, 0.3272705079, 0.6944580080, 0.5113525392, 0.1002197266, 0.7222900392 },
  { 0.6722412111, 0.1112060547, 0.7647705080, 0.4600830079, 0.2769775391, 0.9713134768, 0.3511962891 },
  { 0.1722412110, 0.6112060548, 0.0147705078, 0.5850830079, 0.6519775392, 0.0338134766, 0.6636962892 },
  { 0.2347412110, 0.4237060548, 0.9678955080, 0.6632080080, 0.9801025393, 0.5611572267, 0.0582275391 },
  { 0.7347412111, 0.9237060549, 0.2178955079, 0.2882080079, 0.1051025391, 0.4986572267, 0.9957275393 },
  { 0.9847412112, 0.1737060547, 0.6553955080, 0.5538330079, 0.8707275393, 0.6197509767, 0.1246337891 },
  { 0.4847412111, 0.6737060548, 0.4053955079, 0.4288330079, 0.2457275391, 0.4322509767, 0.9371337893 },
  { 0.3597412110, 0.0487060547, 0.0928955078, 0.8819580080, 0.5738525392, 0.6783447267, 0.2379150391 },
  { 0.8597412111, 0.5487060548, 0.8428955080, 0.0069580078, 0.4488525392, 0.3658447266, 0.8004150392 },
  { 0.6097412111, 0.2987060548, 0.2803955079, 0.7725830080, 0.7144775392, 0.7369384767, 0.1793212891 },
  { 0.1097412110, 0.7987060549, 0.5303955079, 0.1475830078, 0.3394775391, 0.2994384766, 0.8668212893 },
  { 0.0784912110, 0.2674560547, 0.2335205079, 0.4893798829, 0.7906494142, 0.3267822266, 0.5113525392 },
  { 0.5784912111, 0.7674560549, 0.9835205080, 0.6143798830, 0.1656494141, 0.6392822267, 0.4488525392 },
  { 0.8284912111, 0.0174560547, 0.4210205079, 0.3487548829, 0.9312744143, 0.2603759766, 0.5777587892 },
  { 0.3284912110, 0.5174560548, 0.6710205080, 0.7237548830, 0.0562744141, 0.6978759767, 0.3902587892 },
  { 0.4534912110, 0.1424560547, 0.8585205080, 0.2081298829, 0.6343994142, 0.4439697267, 0.6910400392 },
  { 0.9534912112, 0.6424560548, 0.1085205078, 0.8331298830, 0.2593994141, 0.5064697267, 0.2535400391 },
  { 0.7034912111, 0.3924560548, 0.5460205079, 0.0675048828, 0.5250244142, 0.3775634767, 0.6324462892 },
  { 0.2034912110, 0.8924560549, 0.2960205079, 0.9425048830, 0.4000244142, 0.5650634767, 0.3199462891 },
  { 0.1409912110, 0.0799560547, 0.7491455080, 0.8018798830, 0.2281494141, 0.0924072266, 0.9644775393 },
  { 0.6409912111, 0.5799560548, 0.4991455079, 0.1768798829, 0.8531494143, 0.9049072268, 0.0269775391 },
  { 0.8909912111, 0.3299560548, 0.9366455080, 0.9112548830, 0.1187744141, 0.0260009766, 0.9058837893 },
  { 0.3909912110, 0.8299560549, 0.1866455079, 0.0362548828, 0.9937744143, 0.9635009768, 0.0933837891 },
  { 0.2659912110, 0.4549560548, 0.3741455079, 0.5206298829, 0.3218994141, 0.2095947266, 0.7691650392 },
  { 0.7659912111, 0.9549560549, 0.6241455080, 0.3956298829, 0.6968994142, 0.7720947267, 0.2066650391 },
  { 0.5159912111, 0.2049560547, 0.0616455078, 0.6300048830, 0.4625244142, 0.1431884766, 0.8355712893 },
  { 0.0159912109, 0.7049560549, 0.8116455080, 0.2550048829, 0.5875244142, 0.8306884768, 0.1480712891 },
  { 0.0238037109, 0.1190185547, 0.0186767578, 0.1827392579, 0.9136962893, 0.5960693361, 0.2923583985 },
  { 0.5238037111, 0.6190185548, 0.7686767580, 0.8077392580, 0.0386962891, 0.4085693360, 0.7298583986 },
  { 0.7738037111, 0.3690185548, 0.3311767579, 0.0421142578, 0.8043212892, 0.5374755861, 0.3587646485 },
  { 0.2738037110, 0.8690185549, 0.5811767579, 0.9171142580, 0.1793212891, 0.4749755860, 0.6712646486 },
  { 0.3988037110, 0.4940185548, 0.8936767580, 0.4014892579, 0.5074462892, 0.7288818361, 0.4720458985 },
  { 0.8988037111, 0.9940185549, 0.1436767578, 0.5264892579, 0.3824462892, 0.2913818360, 0.5345458986 },
  { 0.6488037111, 0.2440185547, 0.7061767580, 0.2608642579, 0.6480712892, 0.6702880861, 0.4134521485 },
  { 0.1488037110, 0.7440185549, 0.4561767579, 0.6358642580, 0.2730712891, 0.3577880860, 0.6009521486 },
  { 0.2113037110, 0.3065185548, 0.5030517579, 0.6202392580, 0.1011962891, 0.8616943361, 0.2454833985 },
  { 0.7113037111, 0.8065185549, 0.2530517579, 0.4952392579, 0.9761962893, 0.1741943360, 0.8079833986 },
  { 0.9613037112, 0.0565185547, 0.8155517580, 0.7296142580, 0.2418212891, 0.8031005861, 0.1868896485 },
  { 0.4613037110, 0.5565185548, 0.0655517578, 0.3546142579, 0.8668212893, 0.2406005860, 0.8743896486 },
  { 0.3363037110, 0.1815185547, 0.3780517579, 0.8389892580, 0.4449462892, 0.9945068362, 0.0501708984 },
  { 0.8363037111, 0.6815185548, 0.6280517580, 0.2139892579, 0.5699462892, 0.0570068360, 0.9876708987 },
  { 0.5863037111, 0.4315185548, 0.1905517579, 0.9483642580, 0.3355712891, 0.9359130862, 0.1165771485 },
  { 0.0863037110, 0.9315185549, 0.9405517580, 0.0733642578, 0.7105712892, 0.1234130860, 0.9290771487 },
  { 0.1175537110, 0.4002685548, 0.2999267579, 0.2901611329, 0.1617431641, 0.0023193359, 0.6986083986 },
  { 0.6175537111, 0.9002685549, 0.5499267579, 0.6651611330, 0.7867431642, 0.9398193362, 0.2611083985 },
  { 0.8675537111, 0.1502685547, 0.1124267578, 0.4307861329, 0.0523681641, 0.0687255860, 0.6400146486 },
  { 0.3675537110, 0.6502685548, 0.8624267580, 0.5557861329, 0.9273681643, 0.8812255861, 0.3275146485 },
  { 0.4925537111, 0.0252685547, 0.6749267580, 0.0089111328, 0.2554931641, 0.1351318360, 0.5032958986 },
  { 0.9925537112, 0.5252685548, 0.4249267579, 0.8839111330, 0.6304931642, 0.8226318361, 0.4407958985 },
  { 0.7425537111, 0.2752685548, 0.9874267580, 0.1495361328, 0.3961181642, 0.2015380860, 0.5697021486 },
  { 0.2425537110, 0.7752685549, 0.2374267579, 0.7745361330, 0.5211181642, 0.7640380861, 0.3822021485 },
  { 0.1800537110, 0.2127685547, 0.7843017580, 0.9776611330, 0.8492431643, 0.2679443360, 0.7767333986 },
  { 0.6800537111, 0.7127685549, 0.0343017578, 0.1026611328, 0.2242431641, 0.7054443361, 0.2142333985 },
  { 0.9300537112, 0.4627685548, 0.5968017580, 0.8682861330, 0.9898681643, 0.3343505860, 0.8431396486 },
  { 0.4300537110, 0.9627685549, 0.3468017579, 0.2432861329, 0.1148681641, 0.6468505861, 0.1556396485 },
  { 0.3050537110, 0.3377685548, 0.1593017578, 0.6964111330, 0.6929931642, 0.4007568360, 0.9564208987 },
  { 0.8050537111, 0.8377685549, 0.9093017580, 0.3214111329, 0.3179931641, 0.5882568361, 0.0189208984 },
  { 0.5550537111, 0.0877685547, 0.4718017579, 0.5870361329, 0.5836181642, 0.4671630860, 0.8978271486 },
  { 0.0550537110, 0.5877685548, 0.7218017580, 0.4620361329, 0.4586181642, 0.5296630861, 0.0853271485 },
  { 0.0394287109, 0.3533935548, 0.8350830080, 0.7647705080, 0.2847900391, 0.6622314455, 0.6671142580 },
  { 0.5394287111, 0.8533935549, 0.0850830078, 0.1397705078, 0.6597900392, 0.3497314454, 0.3546142579 },
  { 0.7894287111, 0.1033935547, 0.5225830079, 0.9053955080, 0.4254150392, 0.7208251955, 0.7335205080 },
  { 0.2894287110, 0.6033935548, 0.2725830079, 0.0303955078, 0.5504150392, 0.2833251954, 0.2960205079 }
};


// Spatial dimension: 16
// N: 100
// Vectors skipped: 4095
static const double niederreiter_base2_16_100[100][16] =
{
  { 0.0003662109, 0.4705810548, 0.6358642580, 0.9561767580, 0.6715087892, 0.9793701174, 0.6053466798, 0.1983642579, 0.2217731476, 0.3769855500, 0.5390644075, 0.4707050325, 0.2744159699, 0.9942340853, 0.5396728517, 0.0626220703 },
  { 0.5003662111, 0.9705810549, 0.3858642579, 0.0811767578, 0.2965087891, 0.0418701172, 0.4178466798, 0.7608642580, 0.7530231478, 0.5957355501, 0.4453144075, 0.5019550325, 0.7431659700, 0.0254840851, 0.4615478517, 0.9219970705 },
  { 0.7503662111, 0.2205810547, 0.9483642580, 0.8155517580, 0.5621337892, 0.9207763674, 0.5467529298, 0.1397705078, 0.1895465851, 0.4092121125, 0.5087909700, 0.4404315950, 0.3046894074, 0.9639606478, 0.5555419923, 0.0784912110 },
  { 0.2503662110, 0.7205810549, 0.1983642579, 0.1905517579, 0.4371337892, 0.1082763672, 0.4842529298, 0.8272705080, 0.7832965853, 0.5654621126, 0.4775409700, 0.5341815950, 0.7109394075, 0.0577106476, 0.4461669923, 0.9066162111 },
  { 0.3753662110, 0.0955810547, 0.2608642579, 0.7374267580, 0.7652587892, 0.8465576174, 0.6600341798, 0.0030517578, 0.1573200226, 0.4375324250, 0.6035175325, 0.3750019074, 0.3701190949, 0.8985309603, 0.5079345704, 0.0943603516 },
  { 0.8753662111, 0.5955810548, 0.5108642579, 0.3624267579, 0.1402587891, 0.1590576172, 0.3475341798, 0.9405517580, 0.8135700228, 0.5312824251, 0.3847675324, 0.5937519075, 0.6513690950, 0.1172809601, 0.4923095704, 0.8912353518 },
  { 0.6253662111, 0.3455810548, 0.0733642578, 0.5968017580, 0.9058837893, 0.7879638674, 0.7264404299, 0.0694580078, 0.1250934601, 0.4697589875, 0.5732440950, 0.4072284699, 0.3378925324, 0.9307575228, 0.5238037111, 0.1102294922 },
  { 0.1253662110, 0.8455810549, 0.8233642580, 0.4718017579, 0.0308837891, 0.2254638672, 0.2889404298, 0.8819580080, 0.8438434603, 0.5010089875, 0.4169940949, 0.5634784700, 0.6816425325, 0.0870075226, 0.4769287110, 0.8758544924 },
  { 0.1878662110, 0.1580810547, 0.1514892578, 0.2686767579, 0.3590087891, 0.7449951174, 0.9334716799, 0.3389892579, 0.1006793976, 0.2871418000, 0.6367206575, 0.2558612824, 0.4658222200, 0.8106403353, 0.6031494142, 0.0010986328 },
  { 0.6878662111, 0.6580810548, 0.9014892580, 0.6436767580, 0.7340087892, 0.3074951173, 0.1209716797, 0.6514892580, 0.8819293978, 0.6933918001, 0.3554706574, 0.7246112825, 0.5595722200, 0.2168903351, 0.4000244142, 0.9854736330 },
  { 0.9378662112, 0.4080810548, 0.4639892579, 0.3780517579, 0.4996337892, 0.6864013673, 0.9998779299, 0.2803955079, 0.0684528351, 0.2568683625, 0.6689472200, 0.2880878449, 0.4960956575, 0.7803668978, 0.6190185548, 0.0169677734 },
  { 0.4378662110, 0.9080810549, 0.7139892580, 0.5030517579, 0.6246337892, 0.3739013673, 0.0623779297, 0.7178955080, 0.9122028353, 0.7256183626, 0.3251972199, 0.6943378450, 0.5273456575, 0.2491168976, 0.3846435548, 0.9700927737 },
  { 0.3128662110, 0.2830810548, 0.7764892580, 0.0499267578, 0.2027587891, 0.6121826173, 0.8631591799, 0.3936767579, 0.0362262726, 0.3476886750, 0.7011737825, 0.3476581574, 0.4365253450, 0.8399372103, 0.5714111329, 0.0328369141 },
  { 0.8128662111, 0.7830810549, 0.0264892578, 0.9249267580, 0.8277587893, 0.4246826173, 0.1756591797, 0.5811767579, 0.9424762728, 0.6289386751, 0.2949237824, 0.6289081575, 0.5927753450, 0.1836872101, 0.4307861329, 0.9547119143 },
  { 0.5628662111, 0.0330810547, 0.5889892579, 0.1593017578, 0.0933837891, 0.5535888673, 0.8045654299, 0.4600830079, 0.0039997101, 0.3174152375, 0.7334003450, 0.3173847199, 0.4042987824, 0.8721637728, 0.5872802736, 0.0487060547 },
  { 0.0628662110, 0.5330810548, 0.3389892579, 0.7843017580, 0.9683837893, 0.4910888673, 0.2420654297, 0.5225830079, 0.9727497103, 0.6611652376, 0.2646503449, 0.6611347200, 0.6230487825, 0.1534137726, 0.4154052735, 0.9393310549 },
  { 0.0941162110, 0.0018310547, 0.9171142580, 0.5635986329, 0.4195556642, 0.3856201173, 0.3865966798, 0.9796142580, 0.4483356477, 0.1972980500, 0.8125019075, 0.0410175324, 0.1728534699, 0.6114215852, 0.6666259767, 0.2052001954 },
  { 0.5941162111, 0.5018310548, 0.1671142579, 0.4385986329, 0.5445556642, 0.5731201173, 0.5740966798, 0.0421142578, 0.5420856477, 0.7910480501, 0.1562519074, 0.9472675326, 0.8291034700, 0.3926715852, 0.3385009766, 0.7833251955 },
  { 0.8441162111, 0.2518310547, 0.7296142580, 0.7042236330, 0.3101806641, 0.4520263673, 0.4530029298, 0.9210205080, 0.4786090852, 0.2295246125, 0.8447284700, 0.0107440949, 0.1406269074, 0.5811481477, 0.6824951173, 0.1898193360 },
  { 0.3441162110, 0.7518310549, 0.4796142579, 0.3292236329, 0.6851806642, 0.5145263673, 0.5155029298, 0.1085205078, 0.5098590852, 0.7607746126, 0.1259784699, 0.9794940951, 0.8593769075, 0.4248981477, 0.3231201173, 0.7991943361 },
  { 0.4691162110, 0.3768310548, 0.0421142578, 0.8448486330, 0.0133056641, 0.2528076172, 0.3162841798, 0.7843017580, 0.3838825227, 0.1328449250, 0.7519550325, 0.0703144074, 0.2060565949, 0.5157184602, 0.6348876955, 0.2369384766 },
  { 0.9691162112, 0.8768310549, 0.7921142580, 0.2198486329, 0.8883056643, 0.6903076173, 0.6287841798, 0.2218017579, 0.6026325227, 0.8515949251, 0.2207050324, 0.9140644076, 0.7998065950, 0.4844684602, 0.3692626954, 0.7525634767 },
  { 0.7191162111, 0.1268310547, 0.3546142579, 0.9854736330, 0.1539306641, 0.3192138673, 0.2576904297, 0.8507080080, 0.4141559602, 0.1650714875, 0.7841815950, 0.1025409699, 0.2363300324, 0.5479450227, 0.6507568361, 0.2215576172 },
  { 0.2191162110, 0.6268310548, 0.6046142580, 0.1104736328, 0.7789306642, 0.6317138673, 0.6951904298, 0.1632080079, 0.5704059602, 0.8213214876, 0.1904315949, 0.8837909701, 0.7675800325, 0.4541950227, 0.3538818360, 0.7684326174 },
  { 0.1566162110, 0.3143310548, 0.4327392579, 0.1260986328, 0.6070556642, 0.1512451172, 0.0897216797, 0.6202392580, 0.3272418977, 0.1074543000, 0.9726581576, 0.2011737824, 0.1142597199, 0.6778278352, 0.7301025392, 0.1436767578 },
  { 0.6566162111, 0.8143310549, 0.6827392580, 0.7510986330, 0.4820556642, 0.8387451174, 0.9022216799, 0.4327392579, 0.6709918977, 0.8887043001, 0.0039081573, 0.7949237825, 0.8955097201, 0.3340778352, 0.2769775391, 0.8468017580 },
  { 0.9066162111, 0.0643310547, 0.2452392579, 0.0167236328, 0.7476806642, 0.2176513672, 0.0311279297, 0.5616455079, 0.3575153352, 0.0771808624, 0.9423847201, 0.2334003449, 0.0820331574, 0.6475543977, 0.7459716799, 0.1282958985 },
  { 0.4066162110, 0.5643310548, 0.9952392580, 0.8917236330, 0.3726806641, 0.7801513674, 0.9686279299, 0.4991455079, 0.6387653352, 0.9209308626, 0.0361347199, 0.7646503450, 0.9257831576, 0.3663043977, 0.2615966797, 0.8626708986 },
  { 0.2816162110, 0.1893310547, 0.5577392579, 0.4073486329, 0.9508056643, 0.0184326172, 0.1444091797, 0.6749267580, 0.2627887726, 0.0430011749, 0.9121112826, 0.1679706574, 0.0224628449, 0.7071247102, 0.6983642580, 0.1754150391 },
  { 0.7816162111, 0.6893310548, 0.3077392579, 0.5323486329, 0.0758056641, 0.9559326174, 0.8319091799, 0.3624267579, 0.7315387728, 0.9492511751, 0.0683612824, 0.8242206575, 0.9912128451, 0.3008747102, 0.3077392579, 0.8160400393 },
  { 0.5316162111, 0.4393310548, 0.8702392580, 0.2979736329, 0.8414306643, 0.0848388672, 0.2108154297, 0.7413330080, 0.2930622102, 0.0127277374, 0.8818378451, 0.1376972199, 0.0527362824, 0.7393512728, 0.7142333986, 0.1600341797 },
  { 0.0316162109, 0.9393310549, 0.1202392578, 0.6729736330, 0.2164306641, 0.8973388674, 0.7733154299, 0.3038330079, 0.6993122102, 0.9814777377, 0.1005878449, 0.8564472200, 0.9589862826, 0.2706012726, 0.2923583985, 0.8319091799 },
  { 0.0472412109, 0.2362060547, 0.4522705079, 0.1007080078, 0.0426025391, 0.7955322267, 0.4801025392, 0.7025146486, 0.6748981477, 0.7988605501, 0.2421894074, 0.6113300325, 0.5712909700, 0.1973590851, 0.7935791017, 0.3477783204 },
  { 0.5472412111, 0.7362060549, 0.7022705080, 0.9757080080, 0.9176025393, 0.2330322266, 0.5426025392, 0.2650146485, 0.3311481477, 0.2051105500, 0.7734394075, 0.3925800324, 0.4150409699, 0.7911090853, 0.2154541016, 0.6446533205 },
  { 0.7972412111, 0.4862060548, 0.1397705078, 0.2413330079, 0.1832275391, 0.8541259768, 0.4215087892, 0.6361083986, 0.6426715852, 0.7685871126, 0.2119159699, 0.5810565950, 0.6015644075, 0.2295856476, 0.8094482424, 0.3636474610 },
  { 0.2972412110, 0.9862060549, 0.8897705080, 0.8663330080, 0.8082275393, 0.1666259766, 0.6090087892, 0.3236083985, 0.3614215852, 0.2373371125, 0.8056659700, 0.4248065949, 0.3828144074, 0.7608356478, 0.2000732422, 0.6292724611 },
  { 0.4222412110, 0.3612060548, 0.5772705079, 0.3194580079, 0.3863525392, 0.9127197268, 0.2847900391, 0.5072021486, 0.7354450228, 0.8594074251, 0.1816425324, 0.5156269075, 0.5419940950, 0.1641559601, 0.7618408205, 0.3170166016 },
  { 0.9222412112, 0.8612060549, 0.3272705079, 0.6944580080, 0.5113525392, 0.1002197266, 0.7222900392, 0.4447021485, 0.2666950226, 0.1406574250, 0.8378925325, 0.4843769075, 0.4482440950, 0.8204059603, 0.2462158204, 0.6763916017 },
  { 0.6722412111, 0.1112060547, 0.7647705080, 0.4600830079, 0.2769775391, 0.9713134768, 0.3511962891, 0.5657958986, 0.7032184602, 0.8291339876, 0.1513690949, 0.5478534700, 0.5097675325, 0.1338825226, 0.7777099611, 0.3328857423 },
  { 0.1722412110, 0.6112060548, 0.0147705078, 0.5850830079, 0.6519775392, 0.0338134766, 0.6636962892, 0.3782958985, 0.2969684602, 0.1728839875, 0.8701190951, 0.4541034700, 0.4785175325, 0.8526325228, 0.2308349610, 0.6610107423 },
  { 0.2347412110, 0.4237060548, 0.9678955080, 0.6632080080, 0.9801025393, 0.5611572267, 0.0582275391, 0.8431396486, 0.5538043977, 0.8965168001, 0.0898456574, 0.6464862825, 0.6376972200, 0.0137653351, 0.8570556643, 0.2862548829 },
  { 0.7347412111, 0.9237060549, 0.2178955079, 0.2882080079, 0.1051025391, 0.4986572267, 0.9957275393, 0.1556396485, 0.4600543977, 0.1152668000, 0.9335956576, 0.3652362824, 0.3564472199, 0.9825153353, 0.1539306641, 0.7081298830 },
  { 0.9847412112, 0.1737060547, 0.6553955080, 0.5538330079, 0.8707275393, 0.6197509767, 0.1246337891, 0.7767333986, 0.5215778352, 0.9287433626, 0.1220722199, 0.6787128450, 0.6679706575, 0.0459918976, 0.8729248049, 0.3021240235 },
  { 0.4847412111, 0.6737060548, 0.4053955079, 0.4288330079, 0.2457275391, 0.4322509767, 0.9371337893, 0.2142333985, 0.4903278352, 0.0849933624, 0.9033222201, 0.3349628449, 0.3242206574, 0.9522418978, 0.1385498047, 0.6927490236 },
  { 0.3597412110, 0.0487060547, 0.0928955078, 0.8819580080, 0.5738525392, 0.6783447267, 0.2379150391, 0.8978271486, 0.6143512727, 0.9570636751, 0.0292987824, 0.7382831575, 0.7334003450, 0.1055622101, 0.8253173830, 0.2554931641 },
  { 0.8597412111, 0.5487060548, 0.8428955080, 0.0069580078, 0.4488525392, 0.3658447266, 0.8004150392, 0.0853271485, 0.3956012727, 0.0508136749, 0.9980487826, 0.2695331574, 0.2646503449, 0.8868122103, 0.1846923829, 0.7398681642 },
  { 0.6097412111, 0.2987060548, 0.2803955079, 0.7725830080, 0.7144775392, 0.7369384767, 0.1793212891, 0.9564208987, 0.5821247102, 0.9892902377, 0.0615253449, 0.7080097200, 0.7011737825, 0.0752887726, 0.8411865236, 0.2713623048 },
  { 0.1097412110, 0.7987060549, 0.5303955079, 0.1475830078, 0.3394775391, 0.2994384766, 0.8668212893, 0.0189208984, 0.4258747102, 0.0205402374, 0.9677753451, 0.3017597199, 0.2949237824, 0.9190387728, 0.1693115235, 0.7244873049 },
  { 0.0784912110, 0.2674560547, 0.2335205079, 0.4893798829, 0.7906494142, 0.3267822266, 0.5113525392, 0.4837646486, 0.9014606478, 0.6191730501, 0.3906269074, 0.9316425326, 0.9697284701, 0.3145465852, 0.9205322268, 0.4903564454 },
  { 0.5784912111, 0.7674560549, 0.9835205080, 0.6143798830, 0.1656494141, 0.6392822267, 0.4488525392, 0.5462646486, 0.1202106476, 0.4004230500, 0.6093769075, 0.0878925324, 0.0009784698, 0.6582965852, 0.0924072266, 0.5059814454 },
  { 0.8284912111, 0.0174560547, 0.4210205079, 0.3487548829, 0.9312744143, 0.2603759766, 0.5777587892, 0.4173583985, 0.9317340853, 0.5888996126, 0.4228534699, 0.9013690951, 0.9375019076, 0.3467731477, 0.9364013674, 0.4749755860 },
  { 0.3284912110, 0.5174560548, 0.6710205080, 0.7237548830, 0.0562744141, 0.6978759767, 0.3902587892, 0.6048583986, 0.0879840851, 0.4326496125, 0.5791034700, 0.1201190949, 0.0312519074, 0.6280231477, 0.0770263672, 0.5218505861 },
  { 0.4534912110, 0.1424560547, 0.8585205080, 0.2081298829, 0.6343994142, 0.4439697267, 0.6910400392, 0.2884521485, 0.9620075228, 0.5547199251, 0.4550800325, 0.9609394076, 0.8779315951, 0.2813434601, 0.8887939455, 0.4595947267 },
  { 0.9534912112, 0.6424560548, 0.1085205078, 0.8331298830, 0.2593994141, 0.5064697267, 0.2535400391, 0.7259521486, 0.0557575226, 0.4609699250, 0.5488300325, 0.0546894074, 0.0966815949, 0.6875934602, 0.1231689453, 0.5377197267 },
  { 0.7034912111, 0.3924560548, 0.5460205079, 0.0675048828, 0.5250244142, 0.3775634767, 0.6324462892, 0.3470458985, 0.9922809603, 0.5244464875, 0.4873065950, 0.9931659701, 0.9082050326, 0.2510700226, 0.9046630861, 0.4442138673 },
  { 0.2034912110, 0.8924560549, 0.2960205079, 0.9425048830, 0.4000244142, 0.5650634767, 0.3199462891, 0.6595458986, 0.0235309601, 0.4931964875, 0.5185565950, 0.0244159699, 0.0644550324, 0.7198200228, 0.1077880860, 0.5535888673 },
  { 0.1409912110, 0.0799560547, 0.7491455080, 0.8018798830, 0.2281494141, 0.0924072266, 0.9644775393, 0.1243896485, 0.7803668978, 0.7168293001, 0.3007831574, 0.8417987825, 0.7861347200, 0.3809528352, 0.9840087893, 0.4288330079 },
  { 0.6409912111, 0.5799560548, 0.4991455079, 0.1768798829, 0.8531494143, 0.9049072268, 0.0269775391, 0.9368896487, 0.2491168976, 0.3105793000, 0.7070331575, 0.1855487824, 0.1923847199, 0.5997028352, 0.0308837891, 0.5694580079 },
  { 0.8909912111, 0.3299560548, 0.9366455080, 0.9112548830, 0.1187744141, 0.0260009766, 0.9058837893, 0.0579833985, 0.8106403353, 0.7490558626, 0.2705097199, 0.8740253451, 0.7539081575, 0.4131793977, 0.9998779299, 0.4134521485 },
  { 0.3909912110, 0.8299560549, 0.1866455079, 0.0362548828, 0.9937744143, 0.9635009768, 0.0933837891, 0.9954833987, 0.2168903351, 0.2803058625, 0.7392597200, 0.1552753449, 0.2226581574, 0.5694293977, 0.0155029297, 0.5853271486 },
  { 0.2659912110, 0.4549560548, 0.3741455079, 0.5206298829, 0.3218994141, 0.2095947266, 0.7691650392, 0.1790771485, 0.8409137728, 0.6523761751, 0.3652362824, 0.8085956575, 0.8193378450, 0.4727497102, 0.9522705080, 0.3980712892 },
  { 0.7659912111, 0.9549560549, 0.6241455080, 0.3956298829, 0.6968994142, 0.7720947267, 0.2066650391, 0.8665771486, 0.1846637726, 0.3711261750, 0.6464862825, 0.2148456574, 0.1630878449, 0.5039997102, 0.0616455078, 0.6011962892 },
  { 0.5159912111, 0.2049560547, 0.0616455078, 0.6300048830, 0.4625244142, 0.1431884766, 0.8355712893, 0.2376708985, 0.8711872103, 0.6846027376, 0.3349628449, 0.7783222200, 0.8496112825, 0.4424762727, 0.9681396487, 0.3826904298 },
  { 0.0159912109, 0.7049560549, 0.8116455080, 0.2550048829, 0.5875244142, 0.8306884768, 0.1480712891, 0.8001708986, 0.1524372101, 0.3408527375, 0.6787128450, 0.2470722199, 0.1308612824, 0.5362262727, 0.0462646484, 0.6170654298 },
  { 0.0238037109, 0.1190185547, 0.0186767578, 0.1827392579, 0.9136962893, 0.5960693361, 0.2923583985, 0.1285400391, 0.0645160675, 0.2207050324, 0.8828449251, 0.6894855501, 0.9297199251, 0.4326801301, 0.0474853516, 0.5079345704 },
  { 0.5238037111, 0.6190185548, 0.7686767580, 0.8077392580, 0.0386962891, 0.4085693360, 0.7298583986, 0.8160400393, 0.9082660677, 0.7519550325, 0.1015949250, 0.2832355500, 0.0859699249, 0.5889301301, 0.9381103518, 0.4923095704 },
  { 0.7738037111, 0.3690185548, 0.3311767579, 0.0421142578, 0.8043212892, 0.5374755861, 0.3587646485, 0.1949462891, 0.0967426300, 0.1904315949, 0.9150714876, 0.7217121126, 0.8994464876, 0.4004535676, 0.0321044922, 0.5238037111 },
  { 0.2738037110, 0.8690185549, 0.5811767579, 0.9171142580, 0.1793212891, 0.4749755860, 0.6712646486, 0.7574462892, 0.8779926302, 0.7841815950, 0.0713214874, 0.2529621125, 0.1181964875, 0.6192035676, 0.9539794924, 0.4769287110 },
  { 0.3988037110, 0.4940185548, 0.8936767580, 0.4014892579, 0.5074462892, 0.7288818361, 0.4720458985, 0.0738525391, 0.0000629425, 0.1562519074, 0.9472980501, 0.6562824251, 0.9629230502, 0.4619770051, 0.0157470703, 0.5396728517 },
  { 0.8988037111, 0.9940185549, 0.1436767578, 0.5264892579, 0.3824462892, 0.2913818360, 0.5345458986, 0.8863525393, 0.9688129427, 0.8125019075, 0.0410480499, 0.3125324250, 0.0566730499, 0.5557270051, 0.9688720705, 0.4615478517 },
  { 0.6488037111, 0.2440185547, 0.7061767580, 0.2608642579, 0.6480712892, 0.6702880861, 0.4134521485, 0.0152587891, 0.0322895050, 0.1259784699, 0.9795246127, 0.6260089876, 0.9951496127, 0.4922504426, 0.0003662109, 0.5555419923 },
  { 0.1488037110, 0.7440185549, 0.4561767579, 0.6358642580, 0.2730712891, 0.3577880860, 0.6009521486, 0.9527587893, 0.9385395052, 0.8447284700, 0.0107746124, 0.3447589875, 0.0263996124, 0.5235004426, 0.9847412112, 0.4461669923 },
  { 0.2113037110, 0.3065185548, 0.5030517579, 0.6202392580, 0.1011962891, 0.8616943361, 0.2454833985, 0.2691650391, 0.1934223175, 0.0683612824, 0.7930011751, 0.5371418001, 0.8711261751, 0.3740863801, 0.1109619141, 0.5714111329 },
  { 0.7113037111, 0.8065185549, 0.2530517579, 0.4952392579, 0.9761962893, 0.1741943360, 0.8079833986, 0.7066650392, 0.7871723177, 0.9121112826, 0.1992511750, 0.4433918000, 0.1523761750, 0.6553363802, 0.8765869143, 0.4307861329 },
  { 0.9613037112, 0.0565185547, 0.8155517580, 0.7296142580, 0.2418212891, 0.8031005861, 0.1868896485, 0.3355712891, 0.2256488801, 0.1005878449, 0.7627277376, 0.5068683625, 0.8408527376, 0.3418598176, 0.0955810547, 0.5872802736 },
  { 0.4613037110, 0.5565185548, 0.0655517578, 0.3546142579, 0.8668212893, 0.2406005860, 0.8743896486, 0.6480712892, 0.7568988802, 0.8818378451, 0.2314777375, 0.4756183625, 0.1846027375, 0.6856098177, 0.8924560549, 0.4154052735 },
  { 0.3363037110, 0.1815185547, 0.3780517579, 0.8389892580, 0.4449462892, 0.9945068362, 0.0501708984, 0.4644775392, 0.1289691925, 0.0039081573, 0.8574543001, 0.5664386751, 0.7793293001, 0.2783832551, 0.0792236328, 0.6031494142 },
  { 0.8363037111, 0.6815185548, 0.6280517580, 0.2139892579, 0.5699462892, 0.0570068360, 0.9876708987, 0.5269775392, 0.8477191927, 0.9726581576, 0.1387043000, 0.4101886750, 0.2480793000, 0.7471332552, 0.9073486330, 0.4000244142 },
  { 0.5863037111, 0.4315185548, 0.1905517579, 0.9483642580, 0.3355712891, 0.9359130862, 0.1165771485, 0.4058837892, 0.1611957550, 0.0361347199, 0.8271808626, 0.5986652376, 0.8115558626, 0.3086566926, 0.0638427735, 0.6190185548 },
  { 0.0863037110, 0.9315185549, 0.9405517580, 0.0733642578, 0.7105712892, 0.1234130860, 0.9290771487, 0.5933837892, 0.8174457552, 0.9423847201, 0.1709308625, 0.3799152375, 0.2178058625, 0.7149066927, 0.9232177737, 0.3846435548 },
  { 0.1175537110, 0.4002685548, 0.2999267579, 0.2901611329, 0.1617431641, 0.0023193359, 0.6986083986, 0.9097900393, 0.3535785676, 0.4160175324, 0.7187824251, 0.7597980501, 0.5156574250, 0.0498676300, 0.1744384766, 0.6505126955 },
  { 0.6175537111, 0.9002685549, 0.5499267579, 0.6651611330, 0.7867431642, 0.9398193362, 0.2611083985, 0.0972900391, 0.6348285677, 0.5722675325, 0.2500324250, 0.2285480500, 0.4844074250, 0.9561176302, 0.8150634768, 0.3536376954 },
  { 0.8675537111, 0.1502685547, 0.1124267578, 0.4307861329, 0.0523681641, 0.0687255860, 0.6400146486, 0.9761962893, 0.3233051301, 0.3857440949, 0.6885089876, 0.7920246126, 0.5478839876, 0.0176410675, 0.1590576172, 0.6351318361 },
  { 0.3675537110, 0.6502685548, 0.8624267580, 0.5557861329, 0.9273681643, 0.8812255861, 0.3275146485, 0.0386962891, 0.6670551302, 0.6044940950, 0.2822589875, 0.1982746125, 0.4541339875, 0.9863910677, 0.8309326174, 0.3695068360 },
  { 0.4925537111, 0.0252685547, 0.6749267580, 0.0089111328, 0.2554931641, 0.1351318360, 0.5032958986, 0.8551025393, 0.2891254426, 0.4765644075, 0.6582355501, 0.8515949251, 0.6113605501, 0.0791645050, 0.1427001953, 0.6822509767 },
  { 0.9925537112, 0.5252685548, 0.4249267579, 0.8839111330, 0.6304931642, 0.8226318361, 0.4407958985, 0.1676025391, 0.6953754427, 0.5078144075, 0.3144855500, 0.1328449250, 0.3926105500, 0.9229145052, 0.8458251955, 0.3228759766 },
  { 0.7425537111, 0.2752685548, 0.9874267580, 0.1495361328, 0.3961181642, 0.2015380860, 0.5697021486, 0.7965087892, 0.2588520051, 0.4462909700, 0.6279621126, 0.8213214876, 0.5810871126, 0.1094379425, 0.1273193360, 0.6668701173 },
  { 0.2425537110, 0.7752685549, 0.2374267579, 0.7745361330, 0.5211181642, 0.7640380861, 0.3822021485, 0.2340087891, 0.7276020052, 0.5400409700, 0.3467121125, 0.1650714875, 0.4248371125, 0.8906879427, 0.8616943361, 0.3387451173 },
  { 0.1800537110, 0.2127685547, 0.7843017580, 0.9776611330, 0.8492431643, 0.2679443360, 0.7767333986, 0.5504150392, 0.4824848176, 0.2636737824, 0.5664386751, 0.9824543002, 0.7070636751, 0.2412738801, 0.2379150391, 0.7139892580 },
  { 0.6800537111, 0.7127685549, 0.0343017578, 0.1026611328, 0.2242431641, 0.7054443361, 0.2142333985, 0.4879150392, 0.5137348176, 0.7324237825, 0.4101886750, 0.0137042999, 0.3008136750, 0.7725238802, 0.7535400392, 0.2921142579 },
  { 0.9300537112, 0.4627685548, 0.5968017580, 0.8682861330, 0.9898681643, 0.3343505860, 0.8431396486, 0.6168212892, 0.4522113801, 0.2959003449, 0.5986652376, 0.9521808626, 0.7392902376, 0.2090473176, 0.2225341797, 0.6986083986 },
  { 0.4300537110, 0.9627685549, 0.3468017579, 0.2432861329, 0.1148681641, 0.6468505861, 0.1556396485, 0.4293212892, 0.5459613801, 0.7021503450, 0.3799152375, 0.0459308624, 0.2705402375, 0.8027973177, 0.7694091799, 0.3079833985 },
  { 0.3050537110, 0.3377685548, 0.1593017578, 0.6964111330, 0.6929931642, 0.4007568360, 0.9564208987, 0.7457275392, 0.4180316926, 0.3242206574, 0.5058918000, 0.8867511751, 0.6777668001, 0.1455707550, 0.2061767579, 0.7457275392 },
  { 0.8050537111, 0.8377685549, 0.9093017580, 0.3214111329, 0.3179931641, 0.5882568361, 0.0189208984, 0.3082275391, 0.5742816926, 0.6679706575, 0.4746418000, 0.1055011750, 0.3340168000, 0.8643207552, 0.7843017580, 0.2613525391 },
  { 0.5550537111, 0.0877685547, 0.4718017579, 0.5870361329, 0.5836181642, 0.4671630860, 0.8978271486, 0.6871337892, 0.3877582551, 0.3564472199, 0.5381183626, 0.9189777376, 0.6474933626, 0.1758441925, 0.1907958985, 0.7303466799 },
  { 0.0550537110, 0.5877685548, 0.7218017580, 0.4620361329, 0.4586181642, 0.5296630861, 0.0853271485, 0.3746337891, 0.6065082551, 0.6376972200, 0.4443683625, 0.0752277374, 0.3662433625, 0.8320941927, 0.8001708986, 0.2772216798 },
  { 0.0394287109, 0.3533935548, 0.8350830080, 0.7647705080, 0.2847900391, 0.6622314455, 0.6671142580, 0.6326904298, 0.5176410676, 0.5800800325, 0.3359699250, 0.3301105500, 0.2265949250, 0.6358051302, 0.3013916016, 0.7930908205 },
  { 0.5394287111, 0.8533935549, 0.0850830078, 0.1397705078, 0.6597900392, 0.3497314454, 0.3546142579, 0.3201904298, 0.4863910676, 0.4238300324, 0.6797199251, 0.6738605501, 0.7578449251, 0.3545551301, 0.6920166017, 0.2149658204 },
  { 0.7894287111, 0.1033935547, 0.5225830079, 0.9053955080, 0.4254150392, 0.7208251955, 0.7335205080, 0.6912841798, 0.5498676301, 0.6123065950, 0.3681964875, 0.3623371125, 0.1963214875, 0.6660785677, 0.2860107423, 0.8089599611 },
  { 0.2894287110, 0.6033935548, 0.2725830079, 0.0303955078, 0.5504150392, 0.2833251954, 0.2960205079, 0.2537841797, 0.4561176301, 0.3935565949, 0.6494464876, 0.6435871126, 0.7900714876, 0.3223285676, 0.7078857424, 0.1995849610 }
};


QRNG_VALIDATION_TEST_FUNCTIONS(niederreiter_base2)
QRNG_VALIDATION_TEST_DISCARD(niederreiter_base2)

BOOST_AUTO_TEST_CASE( check_generator_limits )
{
  test_niederreiter_base2_max_seed();
  test_niederreiter_base2_max_discard();
  test_niederreiter_base2_max_dimension(BOOST_RANDOM_NIEDERREITER_BASE2_MAX_DIMENSION);
}

BOOST_AUTO_TEST_CASE( validate_niederreiter_base2 )
{
  test_niederreiter_base2_values(niederreiter_base2_02_100, 4095);
  test_niederreiter_base2_values(niederreiter_base2_07_100, 4095);
  test_niederreiter_base2_values(niederreiter_base2_16_100, 4095);
}

BOOST_AUTO_TEST_CASE( validate_niederreiter_base2_seed )
{
  test_niederreiter_base2_seed(niederreiter_base2_02_100, 4095);
  test_niederreiter_base2_seed(niederreiter_base2_07_100, 4095);
  test_niederreiter_base2_seed(niederreiter_base2_16_100, 4095);
}

BOOST_AUTO_TEST_CASE( validate_niederreiter_base2_discard )
{
  test_niederreiter_base2_discard(niederreiter_base2_02_100, 4095);
  test_niederreiter_base2_discard(niederreiter_base2_07_100, 4095);
  test_niederreiter_base2_discard(niederreiter_base2_16_100, 4095);
}
