// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����һ������ڹ���羵������һ��������Ȱٻ����ޡ��ϱ�
�����޶��λ��Σ��Աߴ���һ�����������������������״���
����һʮ���ȡ�

LONG);

  set("exits", ([
        "north"    : __DIR__"bao",
      ]));
  set("objects", ([
        __DIR__"npc/girl"    : 2,
        __DIR__"npc/hou"    : 1,
      ]));
  setup();
}

