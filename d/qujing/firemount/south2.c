// rewritten by snowcat on 4/11/1997
// Room: south2

inherit ROOM;

void create ()
{
  set ("short", "Сɽ����");
  set ("long", @LONG

ɽ������ʯ�������������ǵس���Щ�Ӳݣ���ʱ���м�ֻҰ�ô�ʯ��
��Ծ�������ϲ�Զ����һ��С������Ъ�ŵĺ�ȥ����

LONG);

  set("objects", ([
        __DIR__"npc/qiaofu" : 1,
  ]));
  set("outdoors", "firemount");
  set("exits", ([
        "southeast" : __DIR__"xiaomiao",
        "northup"   : __DIR__"south1",
        "southdown" : __DIR__"south3",
      ]));
      
  setup();
}
