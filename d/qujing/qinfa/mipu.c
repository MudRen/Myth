// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һ���ſ������״����״��򿪣�¶����ɫ�Ĵ��׺���ۡ�
��̨����һʯĥ����ĥ����֮������ϡ���ֻ�չ����������
���ˡ�

LONG);

  set("exits", ([
        "north"    : __DIR__"wugu",
      ]));
  set("objects", ([
"/obj/boss/qinfa_chen"    : 1,
      ]));
  setup();
}

