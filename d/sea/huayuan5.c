// Room: /u/rainy/sea/huayuan5.c
inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

��԰֮�еĲ�ľ������ʢ����ϸ��ȥ����Щ�ڷ����ѵ�һ������Ʒ������
���֣�������Щ�����С���ζ���Ϊ��԰���˼�����Ȥ��������������
���˽��٣�Զû��ǰ�������������

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huayuan4.c",
  "north" : __DIR__"shiwu.c",
]));
//      
        set("water", 1);
//  
  setup();
}
