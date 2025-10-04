/*
 *  Copyright (c) 2014, Oculus VR, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant 
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

/// \file
///


#include "RakNet/NativeFeatureIncludes.h"

#if LIBCAT_SECURITY==1

// If building a RakNet DLL, be sure to tweak the CAT_EXPORT macro meaning
#if !defined(_RAKNET_LIB) && defined(_RAKNET_DLL)
# define CAT_BUILD_DLL
#else
# define CAT_NEUTER_EXPORT
#endif

#include "RakNet/cat/src/port/EndianNeutral.cpp"
#include "RakNet/cat/src/port/AlignedAlloc.cpp"
#include "RakNet/cat/src/time/Clock.cpp"
#include "RakNet/cat/src/threads/Mutex.cpp"
#include "RakNet/cat/src/threads/Thread.cpp"
#include "RakNet/cat/src/threads/WaitableFlag.cpp"
#include "RakNet/cat/src/hash/MurmurHash2.cpp"
#include "RakNet/cat/src/lang/Strings.cpp"

#include "RakNet/cat/src/math/BigRTL.cpp"
#include "RakNet/cat/src/math/BigPseudoMersenne.cpp"
#include "RakNet/cat/src/math/BigTwistedEdwards.cpp"

#include "RakNet/cat/src/crypt/SecureCompare.cpp"
#include "RakNet/cat/src/crypt/cookie/CookieJar.cpp"
#include "RakNet/cat/src/crypt/hash/HMAC_MD5.cpp"
#include "RakNet/cat/src/crypt/privatekey/ChaCha.cpp"
#include "RakNet/cat/src/crypt/hash/Skein.cpp"
#include "RakNet/cat/src/crypt/hash/Skein256.cpp"
#include "RakNet/cat/src/crypt/hash/Skein512.cpp"
#include "RakNet/cat/src/crypt/pass/Passwords.cpp"

#include "RakNet/cat/src/crypt/rand/EntropyWindows.cpp"
#include "RakNet/cat/src/crypt/rand/EntropyLinux.cpp"
#include "RakNet/cat/src/crypt/rand/EntropyWindowsCE.cpp"
#include "RakNet/cat/src/crypt/rand/EntropyGeneric.cpp"
#include "RakNet/cat/src/crypt/rand/Fortuna.cpp"

#include "RakNet/cat/src/crypt/tunnel/KeyAgreement.cpp"
#include "RakNet/cat/src/crypt/tunnel/AuthenticatedEncryption.cpp"
#include "RakNet/cat/src/crypt/tunnel/KeyAgreementInitiator.cpp"
#include "RakNet/cat/src/crypt/tunnel/KeyAgreementResponder.cpp"
#include "RakNet/cat/src/crypt/tunnel/KeyMaker.cpp"

#include "RakNet/cat/src/crypt/tunnel/EasyHandshake.cpp"

#endif // LIBCAT_SECURITY
