inherit NPC;
#include <ansi.h>
int liwu();

int answer_me();

void create()
{
         set_name("���������", ({"caishen"}));
         set("long",
                "����������ʹ���Ĳ������ү���Ǻ�...\n"
                "���������﷢���պ�����������������Ҫ��(ask caishen about �������)\n" );

        set("gender", "����");
        set("title",HIY"Ц�ڳ���,"+HIW"���������"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([           
                       "�������"    :(:liwu:),           
                         ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}

void init()
{
    object ob;
    ::init();
    if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
    
}
void greeting(object ob)
{
        if(!ob || environment(ob)!=environment()) return;

      command("say �������ú���İɣ�\n");
}
int liwu()
{
        object me,ob;
        me=this_player();
        if (!userp(me)){
                command("heng");
                command("say "+"ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }
      if ((int)me->query("combat_exp") <200000 || (int)me->query("mud_age")<18000)
        { command("say "+"�ٺ٣������������ƭ�ң�û�ţ���");
        return 1;}
        if (me->query("combat_exp") < 200000 && (int)me->query("mud_age")<18000)
         { command("say "+"���Ǵ�����?���ǣ��ҿ�ͦ��!");
          return 1;}
         if(me->query("lucky/spring_time") && (me->query("lucky/spring_time")+286400)>time())
          {command("say "+"������˺��������̫̰Ӵ�������������ɣ�\n");
          return 1;}
        me->add("sen",-50);
        me->set("lucky/spring_time",time());    
        ob = new("/d/wizz/liwu/obj/hongbao");
        ob->move(me);
        ob->set("owner",me->query("id"));
    
      message_vision(HIW"����"+HIY"���֣�\n"+HIW"�������ү��"+me->query("name")+"һ��"+HIR"���"NOR+"��\n",this_object(),this_player());

      command("job ��ϲ��ϲ��"+me->query("name")+"�õ��˽��պ��!");
      return 1;
}
