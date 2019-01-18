//  ����֮��  1.0 
// by happ

inherit ROOM;
#include <ansi.h>
int block_cmd(string);

void create ()
{
        set ("short", "������Ե������");
        set ("long", @LONG

����������������    ������ help talk ���˽������ҵ�ʹ�÷���   ����������������

LONG);
        set("exits", ([     
 "north" : "/d/city/kezhan",
        ]));
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init()
{       
        int i;
        object ob = this_player();
           ob->set("channels","none");
           ob->command_function("cls");
	tell_object(ob,HIY"             ��ӭ����������Ե�����ң�\n\n\n\n"NOR);
           ob->set("chat/enter_time",time());
    add_action("block_cmd", "", 1);
    add_action("do_create","create");
    add_action("do_join","join");
    add_action("do_kickout","kk");
    add_action("do_leave","leave");
    add_action("do_say","say");
    add_action("do_list","list");
    add_action("do_lock","lock");
    add_action("do_open","unlock");
    add_action("do_look","look");
}

int block_cmd(string args)
{
        object ob = this_player();
        string verb;
        verb = query_verb();
        if ( verb == "quit" ) return 1;
        if ( verb == "ys" ) return 1;
        if ( verb == "drop" ) return 1;
        return 0;
}
int valid_leave(object me, string dir)
{
        if( me->query_temp("chat/room_name") )
                return notify_fail("�㻹�����������棬������(leave)�ɡ�\n");

        (       time() - me->query("chat/enter_time") < 120 ) ?
me->improve_skill("talk", 0) : me->improve_skill("talk",10);

        tell_object(me,HIG"лл����ӭ�ٴλݹ�������Ե�����ҡ�\n"NOR);   
        me->delete("chat/enter_time");
        return ::valid_leave(me, dir);
}

int do_create(string arg)
   
{
        object ob = this_player();
        object where = this_object();
        int x,i;
        object *list;
        list = all_inventory(this_object());
        i = strlen(arg);

        if( ! arg )
                return notify_fail("��Ҫ����ʲô�����ң�\n");
      
         while(i--) 
                if( arg[i]<=' ' ) {
                        write("�Բ�����������Ҳ����ÿ�����Ԫ��\n");
                        return 1;
                }
        
        if( ob->query_temp("chat/leader") == 1 )
                return notify_fail("�������Ѿ��������ҵ����ˡ�\n");

        list = all_inventory(this_object());

           for(x=0;x<sizeof(list);x++) {
              if(list[x]->query_temp("chat/room_name") == arg )
           return notify_fail(HIC"�Բ����Ѿ�����ʹ����������ң�\n"NOR);
            }

        tell_object(ob,HIR"�������� "HIC+arg+HIR" �����ҡ�\n"NOR);
        ob->set_temp("chat/room_name",arg);
        ob->set_temp("chat/leader",1);
        return 1;
}

int do_list()
{
       
        object *list;
        string name;
        int i;
        list = all_inventory(this_object());

        if( !pointerp( list->query_temp("chat/room_name") ))
            return notify_fail(HIC"����û���κ������ҡ�\n"NOR);
        write("�����Ѿ��������������У�\n" );
    write(HIC"����������������������������������\n"NOR);
        for(i=0;i<sizeof(list);i++)
           {
         if(! list[i]->query_temp("chat/leader") )  continue;
        write(HIG+list[i]->name()+NOR+"  ��  "+HIY+name=list[i]->query_temp("chat/room_name")+NOR+"  ������\n");
        }
    write(HIC"����������������������������������\n"NOR);
        return 1;
}

int do_join(string arg)
{
        object ob = this_player();
        int x;
        object *list;        
        list = all_inventory(this_object());

        if( ! arg)
                return notify_fail("��Ҫ����ʲô�����ң�\n");

        if( ob->query_temp("chat/room_name") &&
         arg != ob->query_temp("chat/room_name") )
                return notify_fail("�����뿪(leave)�����ң�\n");

        if( arg == ob->query_temp("chat/room_name") )
                   return notify_fail("���Ѿ���������������档\n");

          for(x=0;x<sizeof(list);x++)
           {
           if( list[x]->query_temp("chat/room_name") &&
               arg != list[x]->query_temp("chat/room_name") )
            return notify_fail(HIC"�Բ���û����������ң�\n"NOR);
           }

          for(x=0;x<sizeof(list);x++)
           {
           if( arg == list[x]->query_temp("chat/room_name") && 
                      list[x]->query_temp("chat/lock") == 1 )
            return notify_fail(HIC"�Բ��𣬷����Ѿ�������\n"NOR);
           }


        ob->set_temp("chat/room_name",arg);
          for(x=0;x<sizeof(list);x++)
           {
        tell_object(list[x],ob->name()+"�����������ҡ�\n"NOR);
          }
       return 1;
   }

int do_leave()
{
        object ob = this_player();
        object where=this_object();

        if ( ! ob->query_temp("chat/room_name") )
                return notify_fail("������û�м����κ������ҡ�\n");

        tell_room(where,ob->name()+"�뿪��  "+HIC+ob->query_temp("chat/room_name")+NOR+"  �����ҡ�\n");

        ob->delete_temp("chat");
        return 1;
}

int do_kickout(string arg)
{
        int x;
        object ob = this_player();
        object target;
        object *list;
        list = all_inventory(this_object());
   
        if( ! arg )
                return notify_fail("��Ҫ��˭��\n");

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("�㲻�����������ϴ�\n");        

        target=find_player(arg);
        if( target == ob )
                return notify_fail("�㻹���Լ��뿪�ɡ�\n");

        for(x=0;x<sizeof(list);x++)
           {
           if( target->query_temp("chat/room_name") !=
             list[x]->query_temp("chat/room_name") )
            return notify_fail(HIC"�Բ����������������û������ˣ�\n"NOR);
           }

        target->delete_temp("chat/room_name");
        tell_room(this_object(),target->name()+"���ϴ����˳�ȥ��\n"NOR);
        return 1;
}

   int do_lock()
{
        object ob = this_player();

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("�㲻�Ƿ�����ϴ�\n");

        if( ! ob->query_temp("chat/room_name") )
                return notify_fail("��û�м����κ�һ�������ҡ�\n");

        ob->set_temp("chat/lock",1);
        tell_object(ob,"��ѷ�������������\n");
        return 1;
}
        
int do_open()
{
        object ob = this_player();

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("�㲻�Ƿ�����ϴ�\n");

        if( ! ob->query_temp("chat/room_name") )
   
                return notify_fail("��û�м����κ�һ�������ҡ�\n");

        ob->delete_temp("chat/lock");
        tell_object(ob,"��ѷ�����ˡ�\n");
        return 1;
}

int do_say(string arg)
{
        object me = this_player();
        object *ob,*target;
        int i;
        string meroom,obroom;
        string outarg;
        meroom = (string)me->query_temp("chat/room_name");
        if(!meroom) return notify_fail("�㻹���ȼ�������ȴ���һ�������ң�\n");
        ob=all_inventory(this_object());
        i = sizeof(ob);
        while (i--) {
                obroom = (string)ob[i]->query_temp("chat/room_name");
                if ( meroom == obroom ) 
                {
                        if (sizeof(target)==0)
                                   target=({ob[i]});
                         else
                                target+=({ob[i]});
                }
        }
        if(!stringp(outarg = arg))
                outarg = "����������";
        message("vision", HIC"��"GRN+me->query_temp("chat/room_name")+HIC"���䡿"GRN +
        me->query("name") + NOR"(" MAG+ capitalize(me->query("id")) + NOR")" +
        "˵����" HIC+ outarg + "\n" NOR, target);
        tell_room(this_object(),HIR"��������������������������������������������������������������������������\n"NOR);
        return 1;
}

int do_look()
{
        object me = this_player();
        object *ob,*target;
        int i,x,m;
        string meroom,obroom;
        meroom = (string)me->query_temp("chat/room_name");
        if(!meroom) return notify_fail("�㻹���ȼ�������ȴ���һ�������ң�\n");
        ob=all_inventory(this_object());
           i = sizeof(ob);
        while (i--) {
                obroom = (string)ob[i]->query_temp("chat/room_name");
                if ( meroom == obroom )
                {
                        if (sizeof(target)==0)
                                target=({ob[i]});
                         else
                                target+=({ob[i]});
                }
        }
   write("�����ڵ� "+HIC+me->query_temp("chat/room_name")+NOR+" �����������У�\n");
    write(HIC"������������������������������������������\n"NOR);
        for(x=0;x<sizeof(target);x++)
        {
       
         for(m=0;m<sizeof(target);m++)
        if(m%3==2) printf("\n");
        if(target[x]->query_temp("chat/leader"))
        write(HIM+target[x]->name()+"   "NOR);
        else 
        write(GRN+target[x]->name()+"   "NOR);
        }
       write(HIC"\n������������������������������������������\n"NOR);
    write("��ɫ��ʾ���������ˣ�����help talk\n");

       return 1;
}
