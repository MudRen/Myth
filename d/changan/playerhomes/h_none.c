// /d/changan/playerhomes/stdhome.c
// this room is a standard home for married couples.
// wiz should modify /d/changan/phomes.c to set a exit
// and copy this room for them then let the players tell you 
// the descriptions of the room.  

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͷ���Ժͻ�����ŵļ�");
        set("long", @LONG

һ�ж����ú��ˣ�ֻ��һЩ����װ�ޡ�ǽ��(wall)�����ż����ֻ���
LONG
        );
set("item_desc",(["wall": 
"���Ƶ���һ�Σ�����������\n"]));
            set("valid_startroom",1);
        
        set("exits", ([
                "out": "/d/changan/phomes",
            ]));
                                              
        setup();
}

void init()
{
        object me = this_player();
        string id;

        id=(me->parse_command_id_list())[0];

        if (!(id=="none" || id=="miner" )) {
                tell_object(me, "������ �������ˣ�\n");
                tell_object(me, "��ͷ���Է���һ�ţ������������ƨ�� ��
\n");
                tell_object(me, "������ŷ���һ�ţ������������ƨ�� ��
\n");
                me->move("/d/changan/phomes");
                message_vision("$N�ƺ�����һ�����˳�������ɫ�е��Ǳ���\n",
me);
        }
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed" );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move("/d/changan/playerhomes/bed_none");
            message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
                return 1;
}

