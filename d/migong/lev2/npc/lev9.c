// migong lev2

#include <ansi.h>

inherit NPC;

inherit F_MASTER;
void create()
{
        set_name("ɽ��", ({ "shan zei", "zei" }));
        set("race", "����");
        set("gender", "����" );
        set("family/family_name", "����ɽ" );
        set("class", "sanjie" );
        set("long",
"һ�����ҽ��ᣬɱ�˷Ż�Ķ����\n");
        set("attitude", "aggressive"); 
        set("shen_type", 1);      
        set("vendetta/authority",1); 
        set("force_factor",80+random(80));
        set("mana_factor",80+random(80));
        set("max_kee",6000+random(1500));
        set("max_force",8000+random(3000)); 
        set("max_sen",5000+random(1500));
        set("max_mana",8000+random(3000));
        set("mana",15000+random(3000));
        set("force",15000+random(3000));
        set("per", 1);
        set("int", 60);
        set("cor", 40);
        set("age", 22);
        set("daoxing", 1800000);  
        set("combat_exp", 1800000);  
        set("chat_chance", 40);    
        set("chat_msg", ({         
            "ɽ���ȵ������Ǯ��������Ҫ��ɱ���⣡��\n",                         
        }) );
        set("chat_chance_combat", 50); 
        set("chat_msg_combat", ({ 
           (: perform_action, "blade", "leihuo" :),
           (: cast_spell, "zhui" :),   
        }) ); 
        set_skill("unarmed", 250);
        set_skill("blade", 250);
        set_skill("parry", 250);
        set_skill("dodge", 250);     
        set_skill("force", 250);
        set_skill("spells", 250); 
        set_skill("liushenjue", 250);
        set_skill("zileidao", 250);
        set_skill("zhaoyangbu", 250); 
        set_skill("huntianforce", 250);
        set_skill("tianmogong", 250);
        map_skill("unarmed","liushenjue");   
        map_skill("blade","zileidao");
        map_skill("parry","zileidao");
        map_skill("force","huntianforce"); 
        map_skill("spells","tianmogong");         
        map_skill("dodge","zhaoyangbu");  
        add_temp("apply/attack", 100);      
        add_temp("apply/defense", 100);     
        add_temp("apply/armor", 300);      
        add_temp("apply/damage", 100);       
        setup();       
        carry_object("/d/obj/armor/yinjia")->wear();    
        carry_object("/d/obj/weapon/blade/gudingdao")->wield();
        add_money("gold", 1);

}

void init( )
{
        object ob;      
        remove_call_out("hunting");
        if( interactive(ob = this_player())  ) 
        {
                call_out("hunting",1);
        }
        if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) 
        {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) 
                continue;
                if(ob[i]->query("vendetta/authority")) 
                continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}


