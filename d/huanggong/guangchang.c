// Room: /d/huanggong/guangchang.c
inherit ROOM;

void create ()
{
  set ("short", "���쳡");
  set ("long", @LONG

�ʹ�ǰ�Ĵ�㳡��������ж�ʮ�೤���������Ǵ�����ɽ����
����ש�̾ͣ��빬��ĺ�ǽ���߽����ӳ�����ش��¼������
ʱ�ʵ۱��ڴ˻��Ⱥ����������һ���ŵĹ���¥�󣬶�����Ⱥ
���ϳ�ǰ��Ϣ�ĳ�����
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"baihu.c",
  "south" : __DIR__"damen",
  "east" : __DIR__"qinglong.c",
  "northup" : __DIR__"baiyujie.c",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
