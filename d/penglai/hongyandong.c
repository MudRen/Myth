//Cracked by Roath

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "���ն�");
  set ("long", @LONG

һ��ռ�ز�����Ҷ���ʯ�ʯ��ʯ�Σ����õø������ס�
ʯ���Ϸ���һ����֦�������Ƶ���ߣ��ݽǷ���һ¯�ٻ�
�㣬ɢ���ŵ������㡣��¯�߰���һ����ľ���١��ٻ���
����������ʱ�����ڴ�����Ѱٲ����ӡ���á�֯Ů����
���壬��ң���ڡ�
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"penglai",
  "south" : __DIR__"baihuajiao",
  "out": __DIR__"bomingyan",
]));
  set("objects", ([ 
     __DIR__"npc/baihua-xianzi" : 1,
]));
  
  setup();
}
int valid_leave(object me,string dir) {


  object xianzi;
  if (dir=="northdown" || !xianzi=present("baihua xianzi",environment(me)) )
    return ::valid_leave(me,dir);
  if (!living(xianzi)) return ::valid_leave(me,dir);
  if (me->query("family/family_name")!="�¹�") return notify_fail("�ٻ�����һ�Ѿ�ס�㣺�������¹����˲��������\n");
  if (me->query("family/master_name")=="�϶�") return notify_fail("�ٻ�������������ǰ�������˵��������ʦ���������������޵ģ���\n");
  if (dir=="out" && random(2)) {me->start_busy(random(2));return notify_fail("�ٻ�������ס����֣����̵����������������ͱڣ�ǧ��С�ģ���\n");}
  return ::valid_leave(me,dir);
}
