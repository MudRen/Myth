// Room: /d/4world/storage.c
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ǽ��������Ĵ����ң����������ϻ��ﶼ�ǰ����ŷš���Щ��
�����Ҳ��Щ��ǹ���������ﵹ�Ǻܸɾ����������˾�����ɨ��
���������䳡��
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/d/obj/weapon/hammer/stonehammer" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school2",
]));

  setup();
}
