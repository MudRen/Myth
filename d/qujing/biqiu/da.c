// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

������������ܸ����ûʣ��ϱ��Ƕ������ޣ�������������
�����ɶ���÷��������һ�Ű��񴰣������ϵ��Ű׺׷���ͼ��
�������̻���ͨ�����

LONG);

  set("exits", ([
        "east"    : __DIR__"zhaomen",
        "west"    : __DIR__"bao",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"    : 1,
      ]));
  setup();
}

