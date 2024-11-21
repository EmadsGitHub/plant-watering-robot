#pragma DebuggerWindows("debugStream")
task main()
{
char data[] = "Hi";
long fileDescriptor = fileOpenWrite("Report.txt");
fileWriteData(fileDescriptor, data, sizeof(data)/sizeof(data[0]));
fileClose(fileDescriptor);


}
