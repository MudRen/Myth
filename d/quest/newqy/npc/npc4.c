// /d/quest/newdomain/npc/npc4.c
// Created by kuku 2003.5.10 
      
inherit NPC; 
#include <ansi.h> 
 
void create() 
{ 
        set_name( HIY "С��Ů" NOR, ({"xiao xiannv","xiannv"})); 
        set("title",HIR+"ħ������̽�ձ�����"+NOR);  
        set("long", "����һ������������磬���ĸ�ǿ��ֱ��ܷܷŮ�ӣ��������·�Ѱ���ܹ�������ħ������־ʿ��\n");  
        set("gender", "Ů��");  
        set("attitude", "peaceful"); 
        set("class", "xian"); 
        set("age", 16); 
        set("str", 40+random(10)); 
        set("int", 30); 
        set("per", 30+random(4)); 
        set("con", 20); 
        set("max_kee", 50000);    
        set("max_sen", 50000);     
        set("kee", 50000);   
        set("sen", 50000);    
        set("max_force", 30000);   
        set("force", 30000);  
        set("force_factor", 450);  
        set("max_mana", 30000);   
        set("mana", 30000);   
        set("mana_factor", 450);  
        set("combat_exp", 15000000);   
        set("daoxing", 15000000);   
    
        set("inquiry", ([    
                "�ռ�̽��": "�������ȥ̽������Ҫ֪���㽫ȥ�ĵط��Ǻ�Σ�յģ�\n"+
                "����������е���ǰȥһ�ԣ�ȫ����˺��ǻ�õ��ܷ��Ľ����ġ�\n"+
                "������Ѿ������ˣ���ʹ��baoming�ȱ�������Ҫ�߿�������Ӻ�����\n"+
                "����������Ǹ����ض�������ս�����硣\n",
        ]));
         
        setup(); 
         
        carry_object("/d/obj/cloth/nichang")->wear();   
        carry_object("/d/obj/cloth/huazheboots")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();   
} 

void init ()
{
        add_action ("do_baoming","baoming");
}
             
int do_baoming (string arg)
{ 
        int tt,j,k; 
        object *ilist;    
        object me = this_object();
        object who = this_player();
        
        if(who->query("daoxing")<8000000 || who->query("level") < 180){  
                command("say �������ڵ���Ϊȥ̽��̫Σ���ˣ����Ǻú����������ɡ�\n");  
                command("pat " +who->query("id"));  
                return 1;
        } 
        
        if(who->query_temp("yaota/baoming") ){
                command("say �㲻���Ѿ��������������Ե�Ƭ�̡�\n");  
                return 1;
        }
        
        if(me->query("yaota/baoming") >= 8){
                command("say �����Ѿ����ˣ����һ��Сʱ�������ɡ�\n");
                return 1;
        }
        
        ilist = all_inventory(who);
        k=0; 
        j = sizeof(ilist); 
        while (j--) { 
                if( ilist[j]->query("pass_level")<4 ) { 
                        continue; 
                }              
                k++; 
        } 
        if(k < 1) 
                return notify_fail("�㻹û�õ�ȥ̽�������ͨ��֤��\n");  
                         
        if( tt=(int)me->query("yaota/enter") ) { 
                if(tt<=time() && time()<tt+3600) { 
                        message_vision("\n"+me->query("name")+"˵��:���������Ѿ��������㻹�ǵȵ������ɡ�\n",who); 
                        return 1; 
                } 
        } 
        
        message("chat",YEL"��"+HIY"С��Ů"+YEL"����"HIR"ħ������̽��"HIW"���������Ѿ���ʼ����ӭ��ʿ��ǰ��ħ�����磡\n"NOR,users());   
        who->set_temp("yaota/baoming",1);        
        me->add("yaota/baoming",1);
        if( me->query("yaota/baoming") ==8 ){
                remove_call_out("yaota_enter");
                call_out("yaota_enter",300,me);         
        }
        return 1;
}

int yaota_enter(object me)
{
        object passport;
        object who = this_player();
        
        passport = present("passport 4",who);
        
        message("chat",YEL"��"+HIY"С��Ů"+YEL"����"HIR"ħ������̽��"HIW"��������������һСʱ����Լ���������\n"NOR,users());   
        if (who->query_temp("yaota/baoming") && passport && present(who, environment(me)) ){
                message_vision("$N��ͨ��֤����$n��\n", who,me);  
                destruct(passport);
                tell_object(who,HIR"ȥ�����׶༪�ٰ�����Ҫ����Ϊ֮����������㵽�ǳ���������ħ�����磬ף����ˣ�\n"NOR);    
                tell_room(environment(who),HIW"\nͻȻһ��������ƴ����Ʈ������"+who->query("name")+"�������𣬲���һ�̾���ʧ����Ӱ���١�\n"NOR);
                who->move("/d/quest/yaota/gate");
                me->delete("yaota/enter"); 
                who->delete_temp("yaota/baoming");
                me->delete("yaota/baoming");
                me->set("yaota/enter",time());                 
        }        
        return 1; 
} 

void die()  
{ 
        message_vision(HIY"С��Ů"NOR+"��������һ��̾�˿�����\n\n",this_object());  
        message_vision(HIY"С��Ů"NOR+"����һ��������ʧ�ˡ����� \n\n",this_object()); 
        destruct(this_object()); 
} 
