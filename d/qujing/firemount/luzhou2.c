// rewritten by snowcat on 4/11/1997
// room: luzhou2

inherit ROOM;

void create ()
{
  set ("short", "ɳĮ����");
  set ("long", @LONG

�����ļ����ȣ�Զ������������ľ��󡣲�����Ȼˮ�ݷ��������
�������ա����ذ��հ�����ҵ����Ҳ��Ȼ�Եá�

LONG);

  set("exits", ([
        "south" : __DIR__"hongse",
        "north" : __DIR__"xiaodian",
        "west"  : __DIR__"luzhou",
        "east"  : __DIR__"luzhou3",
      ]));
  set("outdoors", "firemount");

  setup();
}
