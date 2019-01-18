//weiqi...97/12/11

inherit NPC;

string apply_dancer(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();

void create()
{
        set_name("�������", ({"gongsun daniang", "gongsun", "daniang"}));
        set("age", 62);
        set("gender", "Ů��");
        set("per", 30);
        set("long", "�����������������ģ���֪�����������˿���û������\n�ر�����Щ����ɧ�ͣ���������ﲻ���ֱ����û���ӡ�\n");
        set("title", "��ʥ");
        set("attitude", "friendly");

        set("combat_exp", 18000000);
  set("daoxing", 6000000);

        set("max_force", 4000);
        set("force", 8000);
        set("force_factor", 200);
        set_skill("unarmed", 260);
        set_skill("dodge", 290);
        set_skill("binfen-steps", 320);
        set_skill("parry", 260);
        set_skill("literate", 290);
        set_skill("sword", 290);
        set_skill("daya-jian", 290);
        map_skill("dodge", "binfen-steps");
        map_skill("sword", "daya-jian");
        map_skill("parry", "daya-jian");


        set("inquiry", ([
                "name" : "����...�������ҹ�������㶼��֪��...\n",
                "here" : "�ٺ�...����������ʤ���������˴������\n",
                "��Ժ" : "�󵨣��������ӽ��£����ҳ����˷����֮�ԣ�\n",
                "��Ů" : "�󵨣��������ӽ��£����ҳ����˷����֮�ԣ�\n",
                "�μ�" : "�󵨣��������ӽ��£����ҳ����˷����֮�ԣ�\n",
                "��¥" : "�󵨣��������ӽ��£����ҳ����˷����֮�ԣ�\n",
                "���" : (: apply_dancer :),
                "��Ů" : (: apply_dancer :),
                "���" : (: apply_dancer :),
                "��Ů" : (: apply_dancer :),
                "leave" : (: answer_leaving :),
                "�뿪" : (: answer_leaving :),
                "����" : "����Ҳѧ��һЩ��ǳ����,һֱû�д���,��Ҳ�Ǽ����£�",
                "���ŹŽ���" : "��˵�ҵĽ�����,�����㵹Ҳ����,������˵������������ڹ����а���,���¿ɷ�Ѱ����",
        ]) );

        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/shoes")->wear();
        carry_object("/d/obj/weapon/sword/snow_sword")->wield();
        add_money("silver", 200);
}

void do_something()
{
        command(sprintf("bet %d silver", 1+random(5)));
        if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
        call_out ("do_something", 120); 
}

string apply_dancer(object me)
{
        me=this_player();
        if( (string)me->query("gender") == "����" ) 
        {
                return "���Ҫ�����µı����ˣ��ҿɰﲻ�϶���æ��\n";
        }
        else
        {
                if( (string)me->query("class") == "dancer" )
                        return "�úøɰɣ��Ժ󲻳�޲��Ϻ��˼ҡ�\n";

                if( (int)me->query("age") >= 30 )
                        return "���²����ˣ����ﻹ����Ѱ��·�ɡ�\n";

                message_vision("������￴��$Nһ��̾�������뷹�ɲ������׳Եġ�\n", me); 
                me->set_temp("dancer_applied", 1);
                return "������������˾��ģ�(yes)\n";
        }
}

string answer_leaving(object me)
{
        me=this_player();
        if( (string)me->query("gender") == "����" ) 
        {
                return "���������ԶԶ�ģ�������ط�����û������\n";
        }
        else
        {
                if( (string)me->query("class") == "dancer" )
                        return "������ţ���Ҷ�֪���ˣ��벻�뿪����ʲô�ֱ��أ�\n";
                else return "���߰ɣ����ﱾ���Ͳ���Ů����ĵط���\n";
        }
}

void init()
{
        ::init();

        remove_call_out("do_something");
        call_out ("do_something", 120);         

        add_action("do_yes", "yes");
}

int do_yes(string arg)
{
        object me;

        me=this_player();
        
        if(me->query_temp("dancer_applied")) 
        {
                message_vision("$N������Ҷ�������ˣ�\n\n", me);
                message_vision("�������������$N��ͷ�����úøɣ�ֻҪ�����Ϻ��������ٻ������ֿɵã�\n", me);
                me->delete_temp("dancer_applied");
                me->set("class", "dancer");
                return 1;
        }

        return 0;
}
int accept_object(object me, object ob)
{
  object skull;
 
  if ((string)ob->query("id")!="jiucai longzhu") {
    command("say ����ô���ԣ�");
    return 0;
  }
  else {
         if (this_player()->query("combat_exp")<1500000 && this_player()->query("daoxing")<2000000 )
        {
                command("say �������Ϊ���ѣ�");
                return 0;}
    if (query_temp("received_longzhu")==1) {
      command("thank "+ me->query("id"));
      command("say ��л�ˡ��ղ���λ��ʿʩ������һ�����ӣ���ſ����Ǽٵġ�");
      command("say "+RANK_D->query_respect(me) +"������ģ����������ˡ�");
      add_temp("received_longzhu", 1);
      return 0;
    }
    else {
        if(query_temp("received_longzhu")<1 || !query_temp("received_longzhu")) {
          command("great " + me->query("id"));
          command("say ��λ" + RANK_D->query_respect(me) + "��ʵ��̫��л�ˣ�");
          command("say ��Ҳûʲô��л�ġ�������ʱ����������Щ����,�ô�һ�׽���,���¸����㡣");
         write("������������:��˿����һ����,�㲻��ȥ(strike)����,������Щ�ջ�\n");
          command("grin");
                  this_player()->set("mark/daya-jian", 1);
          command("say "+ RANK_D->query_respect(me) + "Ī��������졣ǰ;�ն񣬿�Ҫ�����ˡ�");
          add_temp("received_longzhu", 1);
          return 1;
        }
        command("say ��л"+RANK_D->query_respect(me)+"�ĺ��⣬���������Ѿ���һ�������ˡ�");
        return 0;
    }
  }
}
int recognize_apprentice(object ob)
{
        if (this_player()->query("combat_exp")<1500000 && this_player()->query("daoxing")<2000000 )
        return notify_fail("�������Ц�����������Ϊ���ѣ�\n");
        if (this_player()->query("mark/dayagett")!= 1)
        return notify_fail("�������Ц�������Һ���ʦͽ֮Ե��\n");

       if ((int)this_player()->query_skill("sword", 1) < 300){
       message_vision("�������������$N��ͷ����Ӧ���ȸ���ѧ����������\n", this_player());
           }
else {
        if ((int)this_player()->query_skill("daya-jian", 1) > 300)
        return notify_fail("�������Ц������ûʲô���Խ�����,��ȥ�ɣ�\n");
          }
    return 1;
}

