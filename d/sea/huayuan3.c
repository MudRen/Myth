// Room: /u/rainy/sea/huayuan3.c
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
  "west" : __DIR__"huayuan2.c",
  "east" : __DIR__"huayuan4.c",
]));
//      
        set("water", 1);
//  
  setup();
}
