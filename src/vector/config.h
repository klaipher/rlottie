#ifndef CONFIG_H
#define CONFIG_H

// enable threading
#define LOTTIE_THREAD_SUPPORT

// Thread-safe model cache and raster scheduler (the Mac renders from several threads; iOS also passes
// -DLOTTIE_THREAD_SAFE=1 in its BUILD, hence the guard).
#ifndef LOTTIE_THREAD_SAFE
#define LOTTIE_THREAD_SAFE
#endif

//enable logging
//#define LOTTIE_LOGGING_SUPPORT

//enable module building of image loader
//#define LOTTIE_IMAGE_MODULE_SUPPORT

//enable lottie model caching
#define LOTTIE_CACHE_SUPPORT

// disable image loader
#define LOTTIE_IMAGE_MODULE_DISABLED

#endif  // CONFIG_H
