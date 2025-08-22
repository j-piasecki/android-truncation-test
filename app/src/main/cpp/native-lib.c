#include <jni.h>
#include <stdio.h>
#include <android/log.h>

volatile double D = 0xFFFFFFFF;

char* test() {
  char *buffer = NULL;
  volatile int x = (int)D;
  volatile uint32_t u = (uint32_t)D;
  asprintf(&buffer, "%f %x %u\n", D, x, u);
  return buffer;
}

JNIEXPORT jstring JNICALL
Java_io_github_jpiasecki_truncationtest_MainActivity_stringFromJNI(
    JNIEnv* env,
    jobject thiz) {
  char* result = test();

  __android_log_print(ANDROID_LOG_ERROR, "TRUNCATION", "%s", result);

  jstring jresult = (*env)->NewStringUTF(env, result);
  return jresult;
}
