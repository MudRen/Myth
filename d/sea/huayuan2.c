// Room: /u/rainy/sea/huayuan2.c
inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

��԰֮�еĲ�ľ������ʢ����ϸ��ȥ����Щ�ڷ����ѵ�һ������Ʒ������
���֣�������Щ�����С���ζ���Ϊ��԰���˼�����Ȥ��������������
���˽��٣�Զû��ǰ�������������
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beinu" : 1,
]));

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"huayuan1",
  "west" : __DIR__"huilang7.c",
  "east" : __DIR__"huayuan3.c",
]));
//      
        set("water", 1);
//  
  setup();
}
