// created by angell 1/1/2001
// room: /d/qujing/huangfeng/huangfeng1.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

����Ƶ������ط��ᡣ���۵Ĳ��ɴ�أ��̲�����һ��
СϪ��·������ˮ�����ˣ���Ȼһ��������ɫ������ߴ�
һ���ٲ��������������ƺ���ˮ��������

LONG);

  set("exits", ([
	"northup" : __DIR__"huangfeng6",
        "southdown" : __DIR__"huangfeng",
        "eastup" : __DIR__"huangfeng2",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
