// Room: /d/qujing/wudidong/book_cave1
// created 9-15-97 pickle

/************************************************************/
#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);

/************************************************************/
void create ()
{
  set ("short", "��Ѩ");
  set ("long", @LONG

�����ض��ǳ�������Ȼ��������������������Щ΢������⣬����
�Ե���ɭ�ֲ����������ƺ��и���Ӱ���㲻�ɵ�һ����š�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"book-cave2.c",
  "up" : __DIR__"weaponry",
]));

  setup();
}

/************************************************************/
int valid_leave(object me, string dir)
{
    object guard, here=this_object();
    object *inv, container;
    int sizeinv;

    if (dir == "up")
	me->delete_temp("wudidong/gave_bookguard_baozi");
    if (dir != "northdown")
	return ::valid_leave(me, dir);
    if (dir == "northdown"
     && objectp(guard=present("ku lou", here)))
    {
	if (me->query("wudidong/last_entered_book_cave") + 3600 > time())
	{
		message_vision(CYN"����������˵������������ʣ���������������û�ꣿ������Ǹ���ë����Ҫ��֪���ˣ�����Բ��˶����ߣ�\n"NOR, me);
		return notify_fail("");
	}
	inv=all_inventory(me);
	sizeinv=sizeof(inv);
	while (sizeinv--)
	{
	    if (userp(inv[sizeinv]))
	    {
		container=inv[sizeinv];
		break;
	    }
	    if (inv[sizeinv]->is_container())
	    {
		container=inv[sizeinv];
		break;
	    }
	    continue;
	}
	if (container)
	{
	    message_vision(CYN"����������˵�����������"+container->name()+
			   CYN"��ȥ��ʲô����������ë���󿴼�����ô�죡��\n"NOR,me);
	    return notify_fail("");
	}
    }

    if (objectp(guard=present("ku lou", here)))
    {
	if (me->query_temp("wudidong/gave_bookguard_baozi"))
	{
	    message_vision(CYN"����������˵������������Ҫ�Ǹ�����ë�������˾������ˣ�\n"NOR, me);
	    me->set("wudidong/last_entered_book_cave", time());
	    return ::valid_leave(me, dir);
	}
	message_vision(CYN "������Ц����ʲ����û�ţ�\n"NOR, me);
	return notify_fail("");
    }

    message_vision("ǽ�������Ӱ����վ����������ס����ĳ��ڡ�\n", me);
    guard = new(__DIR__"npc/kulou");
    guard->move(here);
    return notify_fail("");

}
