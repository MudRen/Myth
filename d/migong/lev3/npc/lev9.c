// migong lev3

#include <ansi.h>

inherit NPC;

inherit F_MASTER;
void create()
{
        set_name("������", ({ "jiangyang dadao", "dadao" }));
        set("race", "����");
        set("gender", "����" );
        set("family/family_name", "����ɽ" );
        set("class", "sanjie");
        set("long",
"ɱ�˷Ż𣬼������ӣ��޶�����\n");
        set("attitude", "aggressive"); 
        set("shen_type", 1);      
        set("vendetta/authority",1); 
        set("force_factor",120+random(80));
        set("mana_factor",150+random(80));
        set("max_kee",8000+random(1500));
        set("max_force",10000+random(3000)); 
        set("max_sen",8000+random(1500));
        set("max_mana",10000+random(3000));
        set("mana",15000+random(3000));
        set("force",15000+random(3000));
        set("per", 1);
        set("int", 60);
        set("cor", 40);
        set("age", 42);
        set("daoxing", 5000000);  
        set("combat_exp", 5000000);  
        set("chat_chance", 40);    
        set("chat_msg", ({         
            "�������ȵ������Ǯ��������Ҫ��ɱ���⣡��\n",                         
        }) );
        set("chat_chance_combat", 60); 
        set("chat_msg_combat", ({ 
           (: perform_action, "blade", "leihuo" :),
           (: perform_action, "blade", "rimu" :),
           (: perform_action, "blade", "tulong" :),
           (: perform_action, "unarmed", "liushen" :),
           (: cast_spell, "zhui" :),
           (: cast_spell, "sishi" :),
           (: exert_function, "daozhuan" :),
        }) ); 
        set_skill("unarmed", 310);
        set_skill("blade", 310);
        set_skill("parry", 310);
        set_skill("dodge", 310);     
        set_skill("force", 310);
        set_skill("spells", 310); 
        set_skill("liushenjue", 310);
        set_skill("zileidao", 310);
        set_skill("zhaoyangbu", 310); 
        set_skill("huntianforce", 310);
        set_skill("tianmogong", 310);
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



