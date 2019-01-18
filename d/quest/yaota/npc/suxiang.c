//  /d/quest/yaota/npc/suxiang.c
// created by kuku@sjsh  2002.12.8
      
inherit NPC; 
#include <ansi.h> 
int ask_xiangyao();

void create() 
{ 
         set_name( HIW"С��Ů"HIY"����"NOR, ({"xiannv suxiang","suxiang"})); 
        set("title",HIR+"��������"+NOR);  
        set("long", "��������������˼�Ѱ�ҽ�����ħ������֮ʿ��С��Ů������������ȥӺ�ݻ������ȷǷ���\n");  
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
    
        set_skill("unarmed", 600);  
        set_skill("force", 600);  
        set_skill("dodge", 600);  
        set_skill("parry", 600);  
        set_skill("spells", 600);  
        set_skill("sword", 600);  
        set_skill("snowsword",600);  
        set_skill("moonforce",600);  
        set_skill("moonshentong",600);  
        set_skill("moondance",600);  
        set_skill("baihua-zhang",600); 
        map_skill("dodge","moondance");  
        map_skill("unarmed","baihua-zhang");  
        map_skill("force","moonforce");  
        map_skill("spells","moonshentong");  
        map_skill("sword","snowsword");  
        map_skill("parry","snowsword");   
        set("chat_chance_combat", 80);  
        set("chat_msg_combat", ({ 
                (: exert_function, "recover" :),  
                (: perform_action, "sword", "hanyue" :),  
                (: perform_action, "sword", "tian" :),  
        }) );  
        set("inquiry", ([ 
                "����" : (: ask_xiangyao :),
        ]) );
         
        setup(); 
         
        carry_object("/d/obj/cloth/nichang")->wear();   
        carry_object("/d/obj/cloth/huazheboots")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();   
}

void init()
{
        add_action("do_kneel", "kneel");
}

int ask_xiangyao()
{
        object me;
        me = this_player();
        if (!userp(me)){ 
                command("tender"); 
                return 1;
        }
        if( me->query_temp("yaota_passnum") != 8 || me->query("yaotapass")>=3 || !pointerp(me->query_team()) ) {
                command("tender");
        }
        else{
                message_vision("���꣬$N�·𿴼�����¶�������Ц�ݣ���~~��ʥ�������ˣ�\n\n",me);
                command("smile");        
                tell_object(me, "��λ" + RANK_D->query_respect(me) + "��ʥ����ǰҪ����Щ��վ��˵����̫�ðɣ�������г��ģ����ʥ���ͷ(kneel)��\n");
        }
        return 1;
}

int do_kneel()
{
        object me=this_player();
        if( me->query_temp("yaota_passnum") != 8 || me->query("yaotapass")>=3 || !pointerp(me->query_team()) ) 
                return notify_fail("���ﲻ������\n");
        message_vision(HIC "$N˫�ֺ�ʮ�����������ع���������\n\n"NOR,this_player() );
        if(userp(me)){
        if (me->is_team_leader()){
                me->delete_temp("yaota_passnum");
                me->add("combat_exp",800000); 
                me->add("daoxing",800000); 
                me->add("potential",400000); 
                message_vision("$N����$n�����˵��лл����ҽ�����ħ�������ѧ���顢���к�Ǳ�ܶ������ˣ����Ǹ���Ľ���������Ŭ������\n\n",this_player(),this_object() );
                log_file("yaota","["+ctime(time())+"] "+sprintf("%s(%s)�����������õ���80����ѧ��800����к�40��Ǳ�ܡ�\n", me->query("name"),me->query("id")));
        }
        else{
                me->delete_temp("yaota_passnum");
                me->add("combat_exp",600000);
                me->add("daoxing",600000);
                me->add("potential",300000);
                message_vision("$N����$n�����˵��лл����ҽ�����ħ�������ѧ���顢���к�Ǳ�ܶ������ˣ����Ǹ���Ľ���������Ŭ������\n\n",this_player(),this_object() );
                log_file("yaota","["+ctime(time())+"] "+sprintf("%s(%s)�����������õ���60����ѧ��600����к�30��Ǳ�ܡ�\n", me->query("name"),me->query("id")));
        }
        }
        if(me->query("yaotapass")<3) 
                me->add("yaotapass", 1);
                me->set("yaota/done","done");
                me->dismiss_team();  
                me->save();
                return 1;
}
