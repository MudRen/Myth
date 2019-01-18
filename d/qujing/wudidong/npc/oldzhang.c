// laozhang.c
//

inherit NPC;

void create()
{
  set_name("����", ({"lao zhang","zhang", "old zhang"}));
  set("title","ũ��");
  set("gender", "����" );
  set("age", 75);
  set("long", "
��˵��ʮ����ϡ�����Ž�����ʮ���壬�����ӹǶ����������ɻ���Ӳ�Ҫ�˰�æ��
�����˽������Ų�֪�ж������ˣ��е������Լ������ǵ������ˡ�ƽ��������Ц������
�ģ�����֪Ϊʲô������ȴ��ͣ�ذ���̾����\n");
  set("combat_exp", 50000);
  set("attitude", "peaceful");
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set("per", 25);
  set("max_kee", 250);
  set("max_gin", 300);
  set("max_sen", 300);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
  object ob;
  
  ::init();
  set("chat_chance", 7);
  set("inquiry", ([
		   "name" : "�Ҿ������ţ�����������ǡ��ǺǺǡ�����",
		   "here" : "�������żҴ壬�Ҽһ��������š�",
		   "rumors" : " ����кö�������ڴ���������ȥ������è��Ҳ����ץ���ҿ���͵�������򡣡���",
		   "����" : "�Ϻ���������ʮ���꣬����û�������׳�������²��ǳ��˾��ɣ�",
		   "����̾��" : "�Ϻ���ù���������������������������ͷ��������ô��ũ���ѽ��",
		   "������" : "�����ã��Ϻ�������ͷ�㲻˵��ο��ο�������Ϻ�Ҫ������������̫������������������",
		   "��ͷ" : "��ͷ�����������Ƕ��С����ǽ�������ȥ������ʮ�������ģ�",
		   ]) );
  
  set("chat_msg", ({
    "���ſ޵����ҿ�������ͷ������Ÿ����Ϻ���ʮ�겻������ô��ز���������ģ��Ҳ����������ء�����\n",
    "�����������Щ������󣬾��ŵ����ˣ�û��ô���ף���è������ȥ׽���ӣ�����������ˣ�\n",
    "�����ŵ�������ɫ���������ǣ��ǣ�����ʲô�����󣿣������������������������ž�������ȥ��\n",
  }) );
}
int accept_object(object me, object ob)
{
  object skull;
  
  if ((string)ob->query("id")!="li tou") {
    command("say ����ô���ԣ���ɱ�Ϻ��ˡ�");
    return 0;
  }
  else {
    if (query_temp("received_litou")==1) {
      command("thank "+ me->query("id"));
      command("say ��л�ˡ��ղ���λ��ʿʩ���Ϻ�һ����ͷ����һ���ҾͲ���Ҫ�ˡ�");
      command("say �Ϻ�����������������������ݳޡ������ͷ�Ϻ�ʵʵ�������ܲ���");
      command("say "+RANK_D->query_respect(me) +"������ģ��Ϻ����ˡ�");
      command("say ��������Ҷ���ͷ�������������Ϸ��ֵģ���" +RANK_D->query_respect(me) + "�������ã���ȥ�����ɡ�");
      carry_object("/d/qujing/wudidong/obj/skin");
      command("give skin to "+ me->query("id"));
      command("say ������������ܣ�"+RANK_D->query_respect(me)+ "������ϸ���ҡ�");
      command("sigh");
      command("say "+ RANK_D->query_respect(me) + "Ī���Ϻ����졣ǰ;�ն񣬿�Ҫ�����ˡ�");
      add_temp("received_litou", 1);
      return 0;
    }
    else {
        if(query_temp("received_litou")<1 || !query_temp("received_litou")) {
          command("jump " + me->query("id"));
          command("say ��λ" + RANK_D->query_respect(me) + "�����ҵľ��ǣ�ʵ��̫��л�ˣ�");
          command("say �Ϻ�Ҳûʲô��л�ġ������и������ã����������������������������е�ԭ��");
          command("say " + RANK_D->query_respect(me) + "���ǲ��������������°ɡ�");
          carry_object("/d/qujing/wudidong/obj/skull");
          command("give skull to " + me->query("id"));
          command("say �����ú�����������е��ϵ�������Ϻ��Ͳ�����ˡ�");
          command("sigh");
          command("say "+ RANK_D->query_respect(me) + "Ī���Ϻ����졣ǰ;�ն񣬿�Ҫ�����ˡ�");
          add_temp("received_litou", 1);
   	  return 1;
        }
        command("say ��л"+RANK_D->query_respect(me)+"�ĺ��⣬�����Ϻ��Ѿ���һ������ͷ�ˡ�");
        return 0;
    }
  }
}
