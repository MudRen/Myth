// created by kuku@sjsh 2003.2
// ����.���
 
#include <ansi.h> 
inherit ITEM; 
inherit F_AUTOLOAD;

void create() 
{ 
        set_name(HIY "���" NOR, ({ "gold eagle","eagle" }));  
        set_weight(500); 
        set("long", "��Ϊ�������еı���������ܰ������ױ�а���ô���ࡣ\n" ); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("no_sell",1); 
                set("value",0); 
                set("no_give",1);  
                set("no_put",1);  
                set("no_get",1);
                set("no_drop",1);
                set("no_steal",1);
                set("unit","ֻ");  
        } 
        setup(); 
}

void init()
{
         object me = this_object();
        object who = this_player();
        object where = environment(); 
        if (! me->query("my_owner") && interactive (who))
                me->set("my_owner",who->query("id"));
        if (userp(where)){
                if (me->query("owned")){
                        if (me->query("owned")!=where->query("id")){
                                call_out("destruct_me",1);
                        }
                } 
                else{
                        me->set("owned",where->query("id"));
                }
        }
        if(me){
                where->add_temp("apply/attack", where->query_temp("apply/attack")*20/100); 
                where->add_temp("apply/armor",where->query_temp("apply/armor")*30/100);
        }
}

void destruct_me()
{
        destruct (this_object());
}

int query_autoload() { return 1; } 

