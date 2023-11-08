/*
 * File: _coder_maxDistToClosest_info.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 29-Oct-2020 22:18:13
 */

/* Include Files */
#include "_coder_maxDistToClosest_info.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char * data[11] = {
    "789ced5bdf6edb541877a76d6c9a000b342404121542935821eed28d860944f3c769d3a56db26424cdd8e8b17dd2383df6716c2724bdda13a03d00e201b8822b"
    "b81c1217bc005cf0085c7183c4eeb0139f3631398a472ca749cf2745a7a73ff7fcbef3f5f3ef1c7f27e696723b4b1cc7bde27cdcf69f14d7b797070dc77bed05",
    "6ed4fcf892d75ef3f5895de22e8efc1dc1bff15a19eb36ecda830e5275b8dbd624683a1d1d68f06418056baa0e74bbdc332067420ba30e54fa485d45b0ac6a30"
    "8f873a5baad3d1b243d049c785dc9fd30d281f95da1a6736ac5377d170871b8acff794f95f0c189f5d4a7c781ffe507c94b92ba44b421e423b8d1528ec80aeaa",
    "a9c730a35a36d06568e334c216b4ec02342dac7f18ff7855b6e3abf15541035df7a232b920a69dfa6f50fcbb1cd0ff0bbe3eb1abbeeb07767363d07eb041f80f"
    "28e3078ddf150a3fef219aa9a81d558161f15df6f54ff9068882db1282e1e5c736956f147f98cb57c547e9bb42c1c48726d096dd5cb6849d64399f4c09f7e3ab",
    "b71240b0314612ee0a504302522527316c0424011b9640e214f3126252bc82e687bf2576f5e43ff7e4ebdeb7bf27a3e31b58847c3f54defc6d66f3eb52c60b9a"
    "7fd7297cbc0fefeed76ae26152355bb73b9a78a7bc9f2c36c1901f85093c93fce028fda8c667f7f178ff47f3eeafcfc2d2d997287cbc8778d39c38bfb3aaeb39",
    "2adf283e6d3e9074d0bcf122d4f53f9f7eb1d0ba3e53be6975fd0d0a1fefc3d72a1d2c162bb70a4804967cdf36f732f7608ae9fa59b98fa3ddbfbfbb31686f9c"
    "ecdf9f50c60f1abf7728fcbc0f979d471e33a63a0f85a60e504cb5526d15d939dd792c84a62acf6c1df8694abe2a956f147fe1fc713f2bfda8092b246c823f6c",
    "312dc2f5e0c7bfff98dd3e78d1f9a25a0ff63aad74b2bed549948bb77bb2a8e9f16c0d6db1f5e0acac070714ffc2cdbb9ba1e9ff32858ff7e13efdb7648060d7"
    "4863cd00b6ea28f2acf4ffd9947cfb54be513c1cfdff4fd866903f1b8f7f799d3d17ccfb3ad0500cb3563d16e5c3f54c7ebdb7d606c962823d179cb375e0938d",
    "b0f2ee350a1fefc37deb8033fbc1efe7b50e748fca378a87a3ff4eb8bc4c8950efdf7eae30bd9f77bd3f5cafc142b1d1515ab966ba6c54c45da3a28b4cefc978"
    "ec1c77fcf841e37789c2cf7b481d61ec9efecfabce47b11f80a8ded6857ea466b11ff8f9c10d56df99779d4fb4d6f7ca2d94b973946a948b9b25bb95c9c859a6",
    "f3e7e83e766c99d5f7bd6b587d7f7c4b8cd5f7a3e163f5fd70c667fa3fdeffd1bc7b2f34fd7f8bc2c7fbf031f57d60c6c8ae7ffa7dbfdf68fe100b4bff1f4ce0"
    "237838fabf3288db50ee44a8ffdfcdf27b8e8bce1795fe4b8d8f0a551dd94a096b625bdf5a93c4d4f626d3fff3aaff4f29e3058dd7fb143ede87fbf41f1806ea",
    "95fa62966debb2ad623da7171090c9ab1f93ea5e41fd7b75827f04af7b5e7cd900ba824ebf77faeb94fcd2047e8287b33ed0c34a122dba3c7b265d6bb2738179"
    "5f2f30c837250036d3ca5aa26955e370a766f4328bb35eb0fb7bfcbc82e56374ef79a9966500d39adbf7bc029f1f4db1af7023e4ee2c48ac86cf8f0e28fe8578",
    "0e7ce5d3c74cefe75defbfaae4ac2c3afa3c1baf9b25d469ee6debc7c534d37ba6f7aec516ae6ef47fd70356371adf126375a368f858dd68baf1ff053a5500f1",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 17168U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties()
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, *(const char * (*)[6])&
    fldNames[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("maxDistToClosest"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "D:\\CS\\LeetCode\\MaximizeDistancetoClosestPerson-290ct2020\\maxDistToClosest.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738093.92912037042));
  xResult = emlrtCreateStructMatrix(1, 1, 4, *(const char * (*)[4])&b_fldNames[0]);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.4.0.813654 (R2018a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_maxDistToClosest_info.c
 *
 * [EOF]
 */
