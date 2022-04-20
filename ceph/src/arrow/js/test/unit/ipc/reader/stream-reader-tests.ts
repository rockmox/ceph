// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

import {
    generateRandomTables,
    // generateDictionaryTables
} from '../../../data/tables';

import {
    validateRecordBatchReader,
    validateAsyncRecordBatchReader
} from '../validate';

import { ArrowIOTestHelper } from '../helpers';
import { RecordBatchReader } from 'apache-arrow';

for (const table of generateRandomTables([10, 20, 30])) {

    const io = ArrowIOTestHelper.stream(table);
    const name = `[\n ${table.schema.fields.join(',\n ')}\n]`;

    const validate = (source: any) => { validateRecordBatchReader('stream', 3, RecordBatchReader.from(source)); };
    const validateAsync = async (source: any) => { await validateAsyncRecordBatchReader('stream', 3, await RecordBatchReader.from(source)); };
    const validateAsyncWrapped = async (source: any) => { await validateAsyncRecordBatchReader('stream', 3, await RecordBatchReader.from(Promise.resolve(source))); };

    describe(`RecordBatchStreamReader (${name})`, () => {
        describe(`should read all RecordBatches`, () => {
            test(`Uint8Array`, io.buffer(validate));
            test(`Iterable`, io.iterable(validate));
        });
    });

    describe(`AsyncRecordBatchStreamReader (${name})`, () => {
        describe(`should read all RecordBatches`, () => {

            test('AsyncIterable', io.asyncIterable(validateAsync));
            test('fs.FileHandle', io.fsFileHandle(validateAsync));
            test('fs.ReadStream', io.fsReadableStream(validateAsync));
            test('stream.Readable', io.nodeReadableStream(validateAsync));
            test('whatwg.ReadableStream', io.whatwgReadableStream(validateAsync));
            test('whatwg.ReadableByteStream', io.whatwgReadableByteStream(validateAsync));

            test('Promise<AsyncIterable>', io.asyncIterable(validateAsyncWrapped));
            test('Promise<fs.FileHandle>', io.fsFileHandle(validateAsyncWrapped));
            test('Promise<fs.ReadStream>', io.fsReadableStream(validateAsyncWrapped));
            test('Promise<stream.Readable>', io.nodeReadableStream(validateAsyncWrapped));
            test('Promise<ReadableStream>', io.whatwgReadableStream(validateAsyncWrapped));
            test('Promise<ReadableByteStream>', io.whatwgReadableByteStream(validateAsyncWrapped));
        });
    });
}
