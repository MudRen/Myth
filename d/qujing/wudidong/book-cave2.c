// Room: /d/qujing/wudidong/book_cave2
// created 9-14-97 pickle
// Modified By Longer@SJSH

inherit ROOM;
#include <ansi.h>

void create ()
{
  object dao, shu;

  set ("short", "��Ѩ");
  set ("long", @LONG

����Ķ�ѨͻȻ������ࡣ�ıڲ��ż�֧ţ�����򣬷�������������
�Ĺ⡣��Ѩ������ĺܣ����˱��߿�ǽ��һ�ž޴��ʯ���⣬ʲô��
û�С�ӭ��ǽ���ƺ�����һ����(zi)��
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "southup" : __DIR__"book-cave1",
  ]));
  set("item_desc", ([
    "��": RED"������ˣ�����������Ե���������ţ���ǧ����У��������ǣ�"NOR"\n�����ƺ���һ��С�֡�(warning)\n",
    "zi": RED"������ˣ�����������Ե���������ţ���ǧ����У��������ǣ�"NOR"\n�����ƺ���һ��С�֡�(warning)\n",
    "warning": RED"�����Ź治�࣬����̰���������Ϊ֮��\n"NOR,
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/dzls" : 1,
  ]));
  setup();
}

int valid_leave(object me, string dir)
{
    object *inv;
    int i, treasure_count;

    inv=all_inventory(me);
    i=sizeof(inv);
    while (i--)
    {
        if (inv[i]->query("name_recognized") == "�ݹǵ�����")
            treasure_count+=1;
        if (inv[i]->query("name_recognized") == "�ݹǵ�")
            treasure_count+=1;
        continue;
    }
    if (treasure_count > 1)
        return notify_fail("��̫̰���ˣ�\n");
    return ::valid_leave(me, dir);
}

