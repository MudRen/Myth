#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���к�����ģ����ϵ����͵Ʋ�֪�����˶������ˡ���ϡ������
Χ������ܣ�����Ҳ�����˻ҳ������а����������ҳ���ľ����
����ľ�����ҵĵ���һ�ߡ�
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/calvin/milin/bailong",
]));

  setup();
}
