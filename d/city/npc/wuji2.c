

#include <ansi.h>
#include <command.h>
inherit NPC;

int accept_object(object me, object ob);
string change(object me);

void create()
{
        set_name("��������",({ "guan jia","guanjia","huo","xiansheng" }));
        set("gender", "����" );
        set("per", 10);
        set("age", 23);
    set("title", HIW"֪���ܼ�"NOR);
        set("long",
HIC"���ǿ��⸮�ܼ�,���ǿ��⸮�ʷ�
��������׬Ǯ������,����������,�ٺ١�\n"NOR);
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("inquiry", ([
            "����": (: change :),
            "����":  "����û�˾���,ֻҪ��Ǯ,ʲô����,����...��������?",
            "����":  "����û�˾���,ֻҪ��Ǯ,ʲô����,����...��������?",
            "�ɷ�":  "�ɷ�û�˾���,ֻҪ��Ǯ,ʲô����,����...��������?",
        ]) );
        setup();
}

string change(object me)
{
   int p,i;
        me = this_player();
 if ( me->query("couple/change_ask"))
        {
      command("? "+me->query("id"));
            return HIB"�ʹ�Ҳ�Ͱ��ˣ��㲻����������£�\n"NOR;
         }
 if (!me->query("married")){
      command("xbc97 "+me->query("id"));
      command("hmm "+me->query("id"));
      command("say �㻹��δ���ߣ���������ɶ�أ�");   
      return HIB"ȥȥ����ȥ��ȥ......\n"NOR; 
      }
 if (!me->query("marks/couple_times"))
        {
      command("xbc97 "+me->query("id"));
      if ((string)me->query("gender") == "Ů��")         
            command("say �ɷ�û�ˣ���ȷ�ܿ���.....����");
      else command("say ����û�ˣ���ȷ�ܿ���.....����");
      command("poor");    
      message_vision(HIY"�ʷ�˵��͵͵�ذ��˰���,����һ�㣬ֻҪ"NOR+HIR" 100 "NOR+HIB"gold����\n"NOR,me);       
       me->set("couple/change_ask",1);
       return HIB"�����������Ƚ���Ǯ��˵�ˣ�\n"NOR;
          }
      i=(int)me->query("marks/couple_times");
      p=i*i*i*100+100;
      command("xbc97 "+me->query("id"));
      command("grin "+me->query("id"));
      if ((string)me->query("gender") == "Ů��")         
            command("say ����ô����ô������.......����");
      else command("say ����ô����ô��Ů��.....����");
      command("say ��������Ǯ����.��ξ�������ְ�");
      message_vision(HIY"�ʷ�˵��͵͵�ذ��˰���,������Ҫ"NOR+HIR+p+NOR+HIB"gold����\n"NOR,me);
       me->set("couple/change_ask",1);
       return HIB"�����������Ƚ���Ǯ��˵�ˣ�\n"NOR;
}

int accept_object(object me, object ob)
{
    int i,p;
    i=(int)me->query("marks/couple_times");
    p=i*i;
    if (!me->query("couple/change_ask"))
    {
      command("?");
      return notify_fail(HIB"û���ɸ���Ǯ����?�ٺ٣���\n"NOR);
    }
    if(ob->query("money_id") && ob->value() >= (p*1000000+1000000))
    {
        command("nod");
        command("say �ðɣ�"+me->query("name")+"��ȵ�������飡\n"NOR);
      if ((string)me->query("gender") == "Ů��")         
            command("say ��ԭ�����ɷ���"+me->query("couple/name")+",��˵��ɱ�ˣ�");
      else  command("say ��ԭ����������"+me->query("couple/name")+",��˵��ɱ�ˣ�");
        me->delete("couple/change_ask");
        me->set("couple/change_test",1);
        call_out("do_test", 5, me);
        return 1;
        }
       else {
        command("heng");
        command("say �ٺ٣�"+me->query("name")+"�㵹�󵨣����˰������ȥ��\n");
        me->delete_temp("couple/change_ask");
        me->move("/d/kaifeng/tieta");
      message_vision(HIB"$N�����˺۵ر����˳�����\n"NOR,me);
        return 1;
        }
}

string do_test(object me)
{      
       object ob;
       ob=new(LOGIN_OB);
       ob->set("id",me->query("couple/name"));
       if(!ob->restore() && me->query("couple/change_test")){
          command("look " + me->query("id"));
          command("poor " + me->query("id"));
          command("say ���������鲻û��ġ�");
          command("say �Ҿ͸�����������Ե��"); 
      if ((string)me->query("gender") == "����")         
       {
            message("channel:chat",HIW"\n�������쳯��"NOR+HIM"֪���ܼ�"NOR+WHT"(Guan Jia)"NOR+MAG"��"NOR+me->query("name")+HIC"ԭ��������"NOR+me->query("couple/name")+HIC"�Ѿ���ɱ�����ٲ�����ʵ��\n"NOR,users());
            message("channel:chat",HIW"�������쳯��"NOR+HIM"֪���ܼ�"NOR+WHT"(Guan Jia)"NOR+MAG"��"NOR+me->query("name")+HIC"��������Ϊ�����ش˵Ǽǡ�\n"NOR,users());
        }
        else {    message("channel:chat",HIW"\n�������쳯��"NOR+HIM"֪���ܼ�"NOR+WHT"(Guan Jia)"NOR+MAG"��"NOR+me->query("name")+HIC"ԭ�����ɷ�"NOR+me->query("couple/name")+HIC"�Ѿ���ɱ�����ٲ�����ʵ��\n"NOR,users());
            message("channel:chat",HIW"�������쳯��"NOR+HIM"֪���ܼ�"NOR+WHT"(Guan Jia)"NOR+MAG"��"NOR+me->query("name")+HIC"��������Ϊ�����ش˵Ǽǡ�\n"NOR,users());
        }
    if (!me->query("marks/couple_times"))
        me->set("marks/couple_times",1);
      else me->add("marks/couple_times",1);
          me->delete("couple/change_test");
          me->delete("married");
          me->delete("couple");
          me->delete("husband");
          me->delete("wife");   
          return HIB"һ����Ե����������ˣ�\n"NOR; 
         } 
          command("look " + me->query("id"));
          command("? " + me->query("id"));
          command("say �ҿ����鲻����ô�򵥵ġ�");
          command("say �����Ե�ҸĲ��ˡ�"); 
          me->delete("couple/change_test");
          me->delete("couple/change_ask");
          return HIB"��������ˣ�,������Ǯȴû�˵ġ�\n"NOR;
} 
