inherit NPC;
nosave int base_price=5000;
void create()
{
        seteuid(getuid());
        set_name("��ؤ", ({"qi gai", "qi"}));
        set("long", "�����������ڣ��������⣬�����м���������ԭ���Ǹ�������ؤ��\n");
        set("gender","����");
         set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",50000);
        set("attitude","heroism");
        set("chat_chance",10);
        set("chat_msg", ({
        "��ؤ���һ�����룺����.....�����°ɡ�\n",
        "��ؤͻȻ����һЦ��ʩ�Ἰ��Ǯ��......\n",
        "��ؤһ����̾�����Ź������·�ж����ǡ�\n",
        (: random_move :)
        }));
        set_skill("dodge", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("stick", 60);
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 10);
        set("max_kee", 700);
        set("max_gin", 400);
        set("max_sen", 500);

        setup();
        carry_object("/d/obj/cloth/linen")->wear();

}
 

int accept_object(object who, object ob)
{       object m;
        int shishe;

        m=new("/d/ourhome/obj/shuidai.c");
        shishe=ob->value();
                
        if(!ob->query("money_id"))
                {
                command("say ʩ�Ἰ��Ǯ��......");
                write("������ؤ����Ķ���������Ȥ��\n");
                return 0;
                }
        if( shishe < base_price ){
                command("say �����кñ���");
                write("������ؤ�������̫�١�\n");
                return 0;
                }
        else{
              if(objectp(present("shui dai", who)) ){
                  command ( "whisper " + who->query("id") + 
                  " ү�Ĵ�����Իر���������кñ�! \n");
                  return 1;
               }	
              command ( "whisper " + who->query("id") + 
                " ү�Ĵ�����Իر�������һ��˯���ɣ��������⣬�õ��ŵģ�\n");
              m->move(who);
        }
        return 1;
}

