// Room: create by smile 12/10/1998
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", HIC "��ǿ�" NOR);
  set ("long", @LONG

    ��ǿ�ԭ����һ��Сɳ�ӣ��ԴӰ׹Ǿ��ѳ�ʣ���˹Ƕ�
��������������Ķѻ���һ��������׹Ǿ����һ����
�ɴ�ָʹ���°ѿ��ڴ������ʣ�����⡢��ͷ���ӵ���
���ȡ����ǿӡ�
    ���и�ʬɢ����һ���ȳ�ζ��Ѫ���۹��������ǣ��ɴ�
��������һ�����֣�����ȥ�Ĺ���ղ�ҹ�����۶��ɵ���
�ù֣��׹Ǿ���������Ϊ��������ѵ���˳ɱ����׹Ƕ�
�����ñ���
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east": __DIR__"dongnei",
  ]));
  set("objects",([
        __DIR__"npc/kuloubing":3,
        __DIR__"obj/furou":3,
                ]));
  set("outdoors", __DIR__"");                   
  setup();
}

void init()
{
       add_action("do_dive","dive");
       add_action("do_dive", "tiao");
}

int do_dive(string arg)
{
  object me;
    me=this_player();
   if(!arg||(arg!="keng"&&arg!="pits"))
    return notify_fail("��Ҫ��������\n");
    message_vision("$Nһ�������ӵ�������ȥ��",me);
   if(arg=="keng")
     me->move(__DIR__"kengdi1");
   if(arg=="pits")
     me->move(__DIR__"kengdi2");
   return 1;
}
