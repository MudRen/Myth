// Room: create by smile 12/10/1998
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", HIR "Ѫ��" NOR);
  set ("long", @LONG

  [1;31mѪ��[2;37;0m�ǰ׹Ǿ�һ������ƽʱ����ˮ
����Դ��ԭ����һ�������ݽߵ���Ȫ���ԴӰ׹Ǿ�ռ����
������Ϊ��Ѩ��ͻȻ��ʼ����Ѫ���Ȫˮ���׹Ǿ���Ϊ
����������,������Ϊ[1;31mѪ��[2;31;0m��\n
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west": __DIR__"dongnei",
  ]));

  set("resource", ([ /* sizeof() == 1 */
                     "water" : 1,
                                 ]));

  set("outdoors", __DIR__"");                   
  setup();
}
