// Room: /u/rainy/sea/huayuan9.c
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
  "south" : __DIR__"huayuan.c",
  "west" : __DIR__"huilang8.c",
  "east" : __DIR__"huayuan8",
]));
//      
        set("water", 1);
//  
  setup();
}
