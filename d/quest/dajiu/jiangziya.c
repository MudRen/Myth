//modifyed by stey steywen@21cn.com
inherit NPC;
#include <ansi.h>
void create()
{
 
        set_name("������", ({ "jiang ziya", "jiang", "ziya" }) );
        set("gender", "����" );
        set("long", "���������Ƿ�������������ֳ�һ��ͨ�쾵��\n");
        set("age",40);
        set("title", "��˵�е�����");
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("spi", 30);
        set("per", 30);
        set("class", "xian");
        set("attitude", "heroism");
        set("combat_exp", 1500000);
        set("daoxing", 2000000);
        set("max_kee", 20000);
        set("max_sen", 20000);
        set("force",5000);
        set("max_force",3000);
        set("force_factor", 150);
        set("mana", 5000);
        set("max_mana", 3000);
        set("mana_factor", 150);

        set("eff_dx", 600000);
        set("nkgain", 600);

        set_skill("unarmed",170);
        set_skill("dodge",400);
        set_skill("parry",170);
        set_skill("sword", 180);
        set_skill("force", 170);
        set_skill("spells", 170);
        set_skill("changquan", 170);
        set_skill("liangyi-sword", 180);
        set_skill("baguazhou", 170);
        set_skill("moshenbu", 170);
        set_skill("lengquan-force", 170);
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("sword", "liangyi-sword");
        map_skill("parry", "liangyi-sword");
        map_skill("dodge", "moshenbu");
        
        set("chat_chance",1);
        set("chat_msg", ({
                    name()+"˵���������������½��������ң���λ���ɿ�Ըȥ��Ȼ��ɣ�\n",
                    }));

        seteuid(getuid());

        

        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/sky/obj/zhanyaojian")->wield();
}
void init ()
{
  add_action("do_task", "baohu");
  add_action("do_task", "dajiu");
  add_action("do_cancel", "cancel");
}
int do_task()
{
        object me = this_player();
        object guai,xie;
        int level,i;
        int tt;
        string where,msg;
    if( me->query("combat_exp")< 1800000)
        {
tell_object(me,"�����ѧ��Ϊ������������������\n");
     return 1;
       }
        if( (tt=(int)me->query("baohu/job_start")) &&
             me->query("baohu/done")=="done") {
 // job done
            if(tt<=time() &&
                    time()<tt+200) {
                message_vision("$N����ͨ�쾵һ���������Ѵ��,�㻹�ǵȵ�������\n",
                        this_object(), me);
                return 1;
            }
           
        }
        
        me->command("say �����������Ϊ�����ɣ�");
        
        
        if( me->query("baohu/fail") )
             { if(tt<=time() &&
                    time()<tt+600) {
                
                message_vision(CYN"\n������˵����������ʧ���ˣ��ȵ������ѡ�\n"NOR,me);
                return 1;
            }
             
            me->delete("baohu/fail");  
             }
        
        
        if( me->query("baohu/get") )
             {message_vision(CYN"\n������˵�������ɵ��Ŵ���أ������̡�\n"NOR,me);
              return 1;
             }
       
             
           
        //ȷ������ȼ�
        level = random(10);
        if (level<5) level=1;
        else if (level<8) level=2;
        else level=3;
        
        me->set("baohu/get",1);
        me->set("baohu/level",level);
        me->delete("baohu/done");
        guai = new(__DIR__"baohunpc");
        guai->set("baohu/npcstart",time());
        where=guai->invocation(me, level);
        message_vision(CYN"\n������˵����������"+where+"����������°ȥ��
�Ѿ��첻���ˣ���ȥ������ɡ�\n"NOR,me); 
         
          
this_object()->command("job "+me->name()+"�ӵ�һ�����"+guai->name()+"������");
        me->set("baohu/guai",guai);
        me->delete("baohu/job_start");
        me->delete("baohu/kk");
        me->set("baohu/where",where);
        me->set("baohu/start_time",time());
        me->set("baohu/job_start",time());
          
        me->set("baohu/id",guai->query("id"));

        me->set("baohu/name",guai->query("name"));
        me->set_temp("baohu/ob",guai);
        me->delete_temp("baohu/get");
        xie=new(__DIR__"shoes.c");
        xie->move(me);
        
        message_vision("$N���һ˫ˮ��Ь��\n $N��$nһ˫ˮ��Ь��\n",this_object(),this_player());

        msg = me->name()+"�ӵ�һ�����"+guai->name()+"������";
        MONITOR_D->report_system_msg (msg);
        return 1;
}        

int do_cancel()
{
        object me = this_player();
        object guai;
        int tt;
          if (!me->query("baohu/get"))
             {tell_object(me,"��û����������\n"); return 1;}
        if ( (tt=(int)me->query("baohu/job_start"))){
        if(tt<=time() &&
                    time()<tt+600) {
                message_vision("$N˵����ʱ��δ�������ɷ����������ӷ�\n",
                        this_object(), me);
                return 1;
            }
        else{
      
        me->delete_temp("baohu");
            
        me->command("say ���������ӿ�������Ϊ����ȡ�");
        message_vision(CYN"\n������˵�����ðɣ������������ɴ�Ȱɡ�\n"NOR,me);
        me->delete("baohu/fail",1);
        me->delete("baohu/get");
        me->delete("baohu/job_start");
        
        guai=me->query_temp("baohu/ob");
        me->delete("baohu");
        
        if (living(guai))
        {
        destruct(guai);  
          
        }
        me->delete("baohu/name");
        me->delete_temp("baohu");
        return 1;
        }
        }
}       

