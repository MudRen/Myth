//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"��Ĺ����"NOR);
        set("long", @LONG

����һ�䲻���ʯ�ң��ıھ��Ǽ�Ӳ����ʯ������
����ܼ򵥣�һ�Ź�����һ�����š������Ϸ�����
����Ʒ��
LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/yuyi" : 1,
  __DIR__"obj/yuxiao" : 1,
  __DIR__"obj/zixue-blade" : 1,
  __DIR__"obj/mojian" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"mishi.c",

]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

