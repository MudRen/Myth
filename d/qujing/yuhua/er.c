// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�����Ӹ�");
  set ("long", @LONG

�����Ӹ���ɫ��������ű�ǽ��ǽ����һ��������ͼ��������
����һ�����Σ�����������Ʋ輸���ϴ����գ���Լ�ɼ�����
���������ˡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"da",
        "east"   : __DIR__"xiao",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince2"  : 1,
      ]));

  setup();
}



