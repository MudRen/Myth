// created by angell 1/1/2001
// room: /d/qujing/huangfeng/huangfeng.c


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
        "southdown" : __DIR__"tulu3",
        "northup" : __DIR__"huangfeng1",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "northup")
    return 0;
  return ::valid_leave (who, dir);
}
