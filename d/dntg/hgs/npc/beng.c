//sgzl

inherit NPC;

void create()
{
        set_name("������", ({"beng jiangjun","beng","monkey"}));
        set("title","����ɽ��");
        set("gender", "����" );
        set("age", 35);
        set("class","taoist");
        set("long", "һֻ���˾���ͨ��Գ��\n");
        set("combat_exp", 60000);
  set("daoxing", 30000);

        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("spells", 60);

        set("max_kee", 450);
        set("max_gin", 450);
        set("max_sen", 450);

        set("max_force", 600);
        set("force", 600);
        set("force_factor", 30);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);
        setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "�Ҿ��ǻ���ɽˮ�����󽫱�������\n",
                "here" : "����ǻ���ɽ��\n", 
                "����" : "�٣��ҼҴ������ǻ���ɽˮ����������\n", 
                "weapon" : "���ǻ���ɽ��ȱ�����գ�Ҫ�ܸ������ã�\n", 
                "bingqi" : "���ǻ���ɽ��ȱ�����գ�Ҫ�ܸ������ã�\n", 
                "����" : "���ǻ���ɽ��ȱ�����գ�Ҫ�ܸ������ã�\n", 
	 ]) );

        set("chat_msg", ({
	    "������˵����Ҫ�������һ���ɽ�������������\n",	
            "���������������˵���ҵ����Щ������ꪲ��ܵ�������֮�С�\n",
            "��������ͷ˵������������ܸ�Щ�������أ�\n",
        }) );
}

int accept_object(object who, object ob)
{
	object me=this_object();

        if ((string)ob->query("id")!="bing qi") 
          {
           command("say ��������ʲô�ã�");
           message_vision ("\n$N˳�ְ�"+ ob->query("name")+ "���ˡ�\n",me);
           return 1;
           }
        else if (who->query("dntg/donghai")=="begin" || who->query("dntg/donghai")=="allow" 
            || who->query("dntg/donghai")=="done")
          {
          command("say �����Ѿ������ˣ����ʹ��������ˡ�\n");
          return 1;
          }
/*
        else if (who->query("dntg/huaguo")!="done")
          {
          message_vision ("\n$N���������������ǻ���ɽ���ˣ����������ʲô��˼����\n",me);
          return 1;
          }
*/
        else if (random(10) != 1)
	  {
          message_vision ("\n$N�˷ܵĽе���̫���ˣ�Ҫ���ٶ�һ����͸����ˡ�\n",me);
          return 1;
          }
        else 
          {
          command("jump");
          command("say ���������ǵı����ǹ����ˣ����Լ�Ҳ��һ�����ֵļһ�ɣ�\n");
          who->set("dntg/donghai","begin");
          return 1;
          }


}


�
