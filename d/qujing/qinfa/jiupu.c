// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������һ����������Ӵ�����һֱ�̵������������
�ط��žƹ��ӣ��־���͵��ĵ��ӣ���������һЩ����Ƥ�ǡ�
��λ�ƿ���ҡͷ���Եز��ž�ȭ��

LONG);

  set("exits", ([
        "west"    : __DIR__"jiedao3",
      ]));
  set("objects", ([
"/obj/boss/qinfa_zhou"    : 1,
      ]));
  setup();
}

