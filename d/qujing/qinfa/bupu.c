// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������һƥƥ�Ĳ�Ⱦ���Ϻʹ���ϸ�ߣ��ſڹ���һЩ����
�۵��·�����ɴȹձñ��������������һյ�͵ƣ��м�������
����ǽ�Ƿ��š�

LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao2",
      ]));
  set("objects", ([
"/obj/boss/qinfa_li"    : 1,
      ]));
  setup();
}

