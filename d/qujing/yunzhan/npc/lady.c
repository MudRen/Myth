//Cracked by Roath


inherit NPC;
void create()
{
       set_name("����", ({"cui lan","lan","cui"}));
       set("long","���Ǹ�Ա�����Ů�������Ļ�����ò��\n");
       set("gender", "Ů��");
       set("per",39);
       set("age", 18);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("combat_exp", 500);
       set("daoxing", 500);
       set("chat_msg",({
        "����̾Ϣ����ʲôʱ��ſ��ԻؼҰ���"}));
       setup();
       carry_object("/d/gao/obj/pink_cloth")->wear();
}
int accept_object(object who,object ob)
{
            object pig=new(__DIR__"pig");

           if (ob->query("id")=="yuanling cloth") 
             {
              if( ! who->query_temp("pig_killed") )
             {
             command("ah");
             command("sigh");
             command("say ������ֶθ�ǿ����֪�һ��ܲ����ټ����ҵ��衣");
             return 0;
             }
              else
                {
                command("say ��л"+who->query("name")+"����֮����");
                command("follow "+who->query("id"));
                return 1;
                }
                }
           else return 1;
}

