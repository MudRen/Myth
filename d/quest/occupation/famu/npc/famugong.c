inherit NPC;
void create()
{
        set_name("��ľ��",({"famu gong","worker"}));
        set("gender","����");
        set("age",20+random(40));
        set("shen_type",1);
        set("combat_exp",30000+random(40000));
        set("str",40);
        set("per",16);
        set_skill("unarmed",15);
        set_skill("parry",15);
        set_skill("dodge",15);
        set("chat_chance",3);
        set("chat_msg",({
                "��ľ������󸫿�������.\n",
                "��ľ�������鿳��ȱ�ڣ�ʹ��һ�ƣ�����'��һ����������.\n",
                "��ľ���ѿ��µ���ľ���һ�Ѷ�.\n",
        }));
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/quest/occupation/famu/obj/axe")->wield();
        add_money("silver",1);
 }
 
void init()
{
        object ob;
        ::init();
        if (interactive(ob=this_player())&&!is_fighting()){ 
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{ 
        if (!ob||environment(ob)!=environment()) return;
        if (ob->query_temp("work/kan")==1){  
                command("say �����ɻ�İɣ�����(kan wood).\n");
                return;
        }
        else return;
}
