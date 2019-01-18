//talkroom

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "̸����");
        set("long", @LONG

һ��ר��˵���Ļ��Ľ�̸�ҡ�
LONG
        );

        set("exits", ([
                "out" : __DIR__"zoulang"
        ]));

        create_door("out", "��ľ��", "enter", DOOR_CLOSED);

        setup();
}

void init()
{
        object *person, room = environment(this_player());
        int i, num;

        person = all_inventory(room);
                                
        for ( i=0; i<sizeof(person); i++ ) {
                if ( person[i]->is_character() && userp(person[i]) ) num++;
        }

        if ( num > 2 && room->query("locked") ) {
                this_player()->move(__DIR__"zoulang1");
                write("�ٺ٣��������ģ������ȥ��\n");
        }

        add_action("do_lock", "lock");
//        add_action("do_open", "open");
}

/*
int do_open()
{
        object room = environment(this_player());

        room->delete("locked");
        return 1;
}
*/

int do_lock()
{
        object *person, room = environment(this_player());
        mapping exit;
        int i, num;
        string dir;

        if( !(doors["out"]["status"] & DOOR_CLOSED) )
                return notify_fail("�Ż�û�����ģ�\n");

        if ( room->query("locked") )
                return notify_fail("���������ģ�\n");
                                       
        person = all_inventory(room);
                                
        for ( i=0; i<sizeof(person); i++ ) {
                if ( person[i]->is_character() && userp(person[i]) ) num++;
        }                                                               
         
        if ( num < 2 ) 
                return notify_fail("����ֻ����һ���ˣ���˭˵���Ļ��أ����ذ������ϰɡ�\n");
       
        room->set("locked", 1);
                               
        remove_call_out("unlock_door");
        call_out("unlock_door", 1800, room);
                                                                     
        message_vision("$N����˩һ��һ�����ã�����Ц�ݵ�ת��������\n", this_player());                                                           
        write("������������һ��" + num + "���ˡ�\n");
        return 1;
}
                                                                                
                                                                        
int unlock_door(object room)
{
        room->delete("locked");
        write("�����ĵ�һ�������ˣ�\n");
        return 1;
}


