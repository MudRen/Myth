// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "Ϫ��");
  set ("long", @LONG

�ϰ���һƬ�����֣���Ϫ�������������ţ���ʱ�ɼ�Ϫ��Ʈ��
����֦���黨�ꡣ�紵��������Ҷ�������졣

LONG);

  set("exits", ([
        "north"    : __DIR__"xibei",
        "southwest"    : __DIR__"zhuang",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "north")
    message_vision ("$Nһ��̤��Ϫ�����������˹�ȥ��\n",who);
  return 1;
}
