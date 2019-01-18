// liwu.c

inherit NPC;
#include <ansi.h>

#include "2002.h"

int give_newbie();
int give_family();
int give_bag();
int give_book();
int answer_me();
int give_saozhou ();

void create()
{
    set_name("СС����", ({"xiao caishen","caishen"}));
    set ("long", @LONG
���������︺���������ָ���ģ�������Ǹ�������Ϸ������
����Ѱ�����(ask caishen about gift)�����Ҳ����Ҫ(saozhou)
�򹤣���ʼ�Լ�������������(ask caishen about ɨ���)
LONG);
    set("gender", "����");
    set("title",HIY"��ӭ����������"NOR);
    set("age", 20);
    set("max_kee", 10000);
    set("kee", 10000);
    set("per", 40);
    set("attitude", "peaceful");
    set("inquiry", ([ //
        "bonnet"   : "�����С���˿���¡����Ǹ����ã��ҵ���ʦ���ڹ�ʱ�ˣ�����",
        "��������" : "����������ס�����ڣ��пտ��Դ�绰��tel��0755-6888808",
        "stey"     : "stey���Ǳ�����������ô�������ⶼ��֪����",
       "newbie"    :(:give_newbie:),
         "gift"    :(:give_newbie:),
         "����"    :(:give_newbie:),
       "family"    :(:give_family:),
       "��������"  :(:give_newbie:),
       "��������"  :(:give_family:),
        "�ٱ���"   : (: give_bag :),
        "ħ����"   : (: give_book :),
        "name"     : (: answer_me :),
        "ɨ���"   : (: give_saozhou :),
    ]));

    setup();
    carry_object("/d/lingtai/obj/faguan")->wear();
}

int answer_me()
{
    command("say С���ұ��㣡�ٺ� ��\n");
    return 1;
}

int give_newbie()
{
    object who = this_player();

    if (who->query("combat_exp") > 410000)
    {
        command("hammer "+who->query("id") );
        command("say �㶼��ô�����˻�����ôһ��С����ô��");
        return 1;
    }
    if (who->query("lll/gai") == "got")
    {
        command("heng " + who->query("id"));
        command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
    }

    who->add("combat_exp",80000);
    who->add("daoxing",80000);
    who->add("force",800);
    who->add("mana",800);
    who->add("maximum_force",1000);
    who->add("max_mana",1000);
    who->add("max_force",1000);
    who->add("maximum_mana",1000);
    who->add("potential",80000);
    who->set("lll/gai","got");
    message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",
                    this_object(), who);
    command("tell " + who->query("id") + 
       "��ĵ��������˰�ʮ��!\n
        ���Ǳ��������80000��\n
        ��������1000��������1000�㷨������������Enableû�г���������ֵ������²��ô�����˼\n");
    command("chat ��ϲ��ϲ��" + who->query("name") + "�õ����������");
    return 1;
}

int give_family()
{
    object who=this_player();
    string family;

    family=who->query("family/family_name");

    if (who->query("combat_exp") < 5000 )
    {
        command("addoil "+who->query("id") );
        command("say ����������Ҫ���г��ģ��㿴����������ѧ5000,�����������ң���");
        return 1;
    }
    if (who->query("lll/skills") == "got" )
    {
        command("heng " + who->query("id"));
        command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
    }
    if (who->query("combat_exp") > 700000)
    {
        command("hammer "+who->query("id") );
        command("say �㶼��ô�����˻�����ôһ��С����ô��");
        return 1;
    }
    if (!family)
    {
        command("pat " + who->query("id"));
         command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ʦ֮ǰ�������\n"
                 "help menpai�����������񻰡��ĸ������ɽ��ܡ�\n");
         return 1;
    }

    STATU_D->set_npc_skill(who, 50, family);
    who->set("lll/skills","got");
    command("nod "+who->query("id") );
    command("chat " + family + "����" + who->query("name") 
            + "�õ������ɽ�����ϣ���Ժ��Ϊ���������⡣");
    return 1;
}

#if 0
void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}

void greeting(object who)
{
return;
    if (!who || environment(who) != environment()) return;
if (who->query("mudring/merry") > 0)
return;
    if (who->query("combat_exp") < 600000)
    {
who->add("potential", 20000);
who->add("combat_exp", 20000);
who->add("daoxing", 20000);
/*
        tell_object(who,"СС�������ĸ����㣺��������Ҫ����Ŷ(ask)(l xiao caishen)��\n");
        tell_object(who,"СС�������ĸ����㣺��������Ҫ��������Ŷ(ask caishen about family)��\n");
*/
    }
who->add("potential", 20000);
who->add("combat_exp", 20000);
who->add("daoxing", 20000);
tell_object(who,BLINK HIM"\n\n\n\n\t\tMerry Christmas!\n\n"NOR);
tell_object(who,BLINK HIM"\n\n\t\t��������ʦ��ף��ʥ�����֣�\n\n"NOR);
who->set("mudring/merry", 1);
}
#endif

int give_bag()
{
    object bag,who;
    who = this_player();

    if (who->query("daoxing") < 500000 && !metep(who))
    {
        command("addoil "+who->query("id") );
        command("say �ðٱ�����Ҫ��������,�����������ң�");
        return 1;
    }

    if (present("baibao bag",who))
    {
         message_vision("$N����$n����һ����\n",this_object(), who);
         return 1;
    }
    bag =new("/obj/sjsh_bag");
    if (!objectp(bag))
    {
        command("say �ٱ���һʱ���õ����ȵȣ�");
        return 1;
    }

    bag->set("owner_id", who->query("id"));
    who->start_busy(3);
 
    if (!who->query("sjsh_bag"))
    {
        who->set("sjsh_bag",1);
        bag->save();
        who->save();
    }
    if (bag->restore())
    {
        bag->save();
        bag->move(who);
        message_vision("$N����$n���ص�Ц��Ц��\n$N�ó�һ�������񻰰ٱ�������$n��\n",
                       this_object(), who);
        return 1;
    } else
    {
        command("say �ٱ���һʱ���õ����ȵȣ�");
        destruct(bag); 
        return 1;
    }
}

int give_book()
{       
    object book, who;
    who = this_player();

    if (present("magic book",who))
    {
        message_vision("$N����$n����һ����\n",this_object(),this_player());
        return 1;
    }
         
    book =new("/obj/book/magic_book");
    if (!book)
    {
         command("say ħ����һʱ���õ����ȵȣ�");
         return 1;
    }

    book->set("owner_id",who->query("id"));
    who->start_busy(3);

    book->move(who);
    message_vision("$N����$n���ص�Ц��Ц��\n$N�ó�һ��"+book->name()+"����$n��\n",
                   this_object(),who);
    return 1;
}

int give_saozhou ()
{
    object ob;
    object who = this_player();

    if (present("sao zhou", who))
    {
        command_function("hmm");
        tell_object(who, CYN"�㲻�Ǹ��ù����뵹������\n"NOR);
        return 1;
    }
    command_function("nod");
    ob = new("/d/quest/small/saozhou");
    ob->move(who);
    tell_object(who, CYN"СС�����ó�һ�Ѵ�ɨ����㣬ȥɨ��ְɣ�\n"NOR);
    tell_object(who, "�������(look saozhou)����ð�����\n");
    return 1;
}

