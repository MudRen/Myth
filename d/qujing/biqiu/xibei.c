// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "Ϫ��");
  set ("long", @LONG

������һ����Ϫ�ڳ������������ţ�Ϫ��Ʈ��������֦���ꡣ
�������������������泤֦�������衣

LONG);

  set("exits", ([
        "north"    : __DIR__"liu4",
        "south"    : __DIR__"xinan",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "south")
    message_vision ("$Nһ��̤��Ϫ�����������˹�ȥ��\n",who);
  return 1;
}
