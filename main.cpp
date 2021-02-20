#include <orc/OrcFile.hh>

int main() {
  ORC_UNIQUE_PTR<orc::OutputStream> outStream = orc::writeLocalFile("my-file.orc");
  ORC_UNIQUE_PTR<orc::Type> schema(
    orc::Type::buildTypeFromString("struct<x:int,y:int>"));
  orc::WriterOptions options;
  ORC_UNIQUE_PTR<orc::Writer> writer =
  createWriter(*schema, outStream.get(), options);
  return 0;
}