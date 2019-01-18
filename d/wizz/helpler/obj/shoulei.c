inherit ITEM;
#include <ansi.h>
mapping default_dirs = ([
        "north":                "��",
        "south":                "��",
        "east":                 "��",
        "west":                 "��",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":                   "��",
        "down":                 "��",
        "out":                  "��",
        "enter":                "��",
]);

// inherit ITEM;

void create()
{
        set_name("����",({"shoulei","lei"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
//                set("no_drop", 0);
//                set("no_get",0);                
                set("unit","��");
                set("material","steel");
        }
        setup();
}
void init()
{
        add_action("do_tou","tou");
}
int do_tou(string str)
{
        string room;
        object me,here,o_room;
        me=this_player();
        if(!str)        return notify_fail("��ҪͶ���ĸ�����\n");

        here=environment(me);

        if(!here->query("exits/"+str))      return notify_fail("û���������\n");

        room=here->query("exits/"+str);

        if(!o_room=find_object(room))
                o_room=load_object(room);
         message_vision(RED"$N��ö���׳���"+default_dirs[str]+"Ͷ�˹�ȥ��\n"NOR,me);
        tell_object(o_room,RED"һöð�Ż𻨵����ײ�֪��˭���˹�����\n"NOR);
        this_object()->set("long","������ð�̵����ף��ۿ���Ҫ��ը����\n");
        this_object()->set("name",RED"ð�̵�����"NOR);
        this_object()->set("no_get",1);
        this_object()->move(o_room);
        call_out("do_zha",3);
        return 1;
}
int do_zha()
{
        object *inv,room,other;
        string *list,s_room;
        mapping exit;
        int i;
        room=environment(this_object());
        inv=all_inventory(room);
        tell_object(room,RED"ֻ�������䡱��һ�����죡\n"NOR);
        if(sizeof(inv)>0)       {
                for(i=0;i<sizeof(inv);i++)      {
        if(inv[i]->is_character())      {
                if(userp(inv[i])&&inv[i]->query("id")!="leon") 
                        message("channel:rumor", YEL +"��ҥ�ԡ�"+ "ĳ�ˣ�"+inv[i]->query("name")+"������ը���ˡ�\n"NOR,users());
                inv[i]->die();
        }
                }
        }
        if(room->query("leon_flag/shoulei")==0)       {
        room->set("short",YEL"�������۵�"NOR+room->query("short"));
        room->set("leon_flag/shoulei",1);
        }
        exit=room->query("exits");
        list=keys(exit);
        for(i=0;i<sizeof(list);i++)     {
        s_room=room->query("exits/"+list[i]);
        if(!other=find_object(s_room))  other=load_object(s_room);
        tell_object(other,RED"����ͻȻ�������ҵı�ը����\n"NOR);
        }
        destruct(this_object());
        return 1;
}

