// Room: /u/rainy/sea/huayuan.c
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
  "south" : __DIR__"inside4.c",
  "north" : __DIR__"huayuan9",
]));
//      
        set("water", 1);
//  
  setup();
}
