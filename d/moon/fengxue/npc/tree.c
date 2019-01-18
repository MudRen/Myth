// modified by xuanzi

#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "�������֣������������������Ϸ��",
        "Ϊʲ���ҵľ����񶼲���ָ���",
        "��˭���Ը���һЩǮ��",
        "������˶������ң�",
        "�ɲ����Ը���������������� ��",
        "�����ǲ������ӿ��ˣ�",
        "�ҿ����ǰ���һ�������춼�����������",
        "�Ұ����μǣ��Ǻǡ���",
        "��û������˯����",
});

string *rnd_say1 = ({
        "С�������������һ������֦��ͱͱ����ͱͱ��ι�������ѣ��������ˡ�",
        "С�������˫�ֱ�ȭ�����˸�Ҿ������λ�ɳ����ˣ�",
        "С����������š���һ����һ��������ֹ�����ӡ�",
        "С���������ȭ����һת����߯�����˵������λ�����ǣ�һ��ɺã�",
        "С�����������̾�˿�������ô��ý��ã���û��һ����ϲ���ң� ",
        "С����������εεظ���Ҵ��˸��к�����λ��磬���ǵ�С���������",
        "С�������ҡ��ҡͷ��̾�������������������£����Ĳ��Ű���",
        "С�����������һ����Ƿ���������һ�������ӡ�:)~~~",
        "С�������˵����ι����Ҷ�ȥ�Ҽ���MM����mud�ѣ�",
        "С�����������һ�����������۰�����",
        "С��������ճյؿ��Ŵ��⣬˵�������ȥ���档",
        "С�������̾��һ��������Ҷ��ڷ�����",
});

varargs void drool(string msg, string who);
void rndchat(); 
int about_here();

void create()
{
        string name, id;

        set_name("С�������", ({ "tree" }) );
        set("title", "��������ͯ");
        set("nickname",HIC" С������ "NOR);
        set("gender", "����");
        set("age", 14);
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("max_kee",5000);
        set("max_sen",5000);
        set("kee",5000);
        set("sen",5000);
        set("max_force",4000);
        set("force",8000);
        set("force_factor",200);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",200);
        set("env/wimpy", 100);
        set_skill("unarmed",400);
        set_skill("dodge",400);
        set_skill("parry",400);
        set("chat_chance", 2);
        set("chat_msg", ({
         (: rndchat :),
                 (: drool :),
        }) );
    set("inquiry", ([
     "name" : "��û����ô������һ���������Ү��@.@",
     "here" : "�ţ�������Ǵ�˵�еķ�ѩ����ˡ�",
     "������":(: about_here() :),
    ]) );

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
        && !ob->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void rndchat()
{
   switch (random(4))
   {
   case 0:command("chat "+rnd_say[random(sizeof(rnd_say))]);break;
   case 1:command("chat* "+rnd_say1[random(sizeof(rnd_say1))]);break;
   default:
   }
   return;
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
    if (ob->query("gender")=="����")
    {   
      command("hi "+ob->query("id"));
      command("brother "+ob->query("id"));
    }
    else {
      command("hi "+ob->query("id"));      
      command("sister "+ob->query("id"));
      }
}


int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "Ү", "");
        msg = replace_string(msg, "��", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;

        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                call_out("drool",1,msg,ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                if( random(10)<5 ) {
                        command("say Ϊʲ�����ң���ʹҮ��");
                        break;
                }
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) )
        {
                if (random(10)<7)
                        command("chat ��ô��Ҷ���˵���ˣ����ǻ�������\n");
                else if (random(10)<8)
                        command("chat " +  rnd_say[random(sizeof(rnd_say))]);
                return;
        }

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "tree") >= 0)||(strsrch(msg, "С�������") >= 0))
        {       
        if((strsrch(msg, "ȥҲ") >= 0)|| (strsrch(msg, "���") >= 0)|| strsrch(msg,"��") >= 0 || (strsrch(msg, "bye") >= 0)|| (strsrch(msg, "ɢ") >= 0)|| (strsrch(msg, "��") >= 0))
        {       
                if( sscanf(msg, "%*sbye%s", msg) == 2 ) msg = "bye" + msg;
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                if( sscanf(msg, "%*sɢ%s", msg) == 2 ) msg = "ɢ" + msg;
                if( sscanf(msg, "%*s���%s", msg) == 2 ) msg = "���" + msg;
                switch(random(10)) {
                case 0: command("chat "+who+",�����Ҫ����\n"); break;
                case 1: command("chat �㲻�ǿ���Ц��?\n");      break;
                case 2: command("chat �Ǹ�����,MUD�����û�ô�.\n"); break;
                case 3: command("chat* С����������˵�ͷ.\n"); break;
                case 4:command("chat* С������������������.\n"); break;
                case 5:command("chat* С���������ŵ��� "+who+",����Ҫ���˾ͱ��ٻ�����\n"); break;
                case 6: command("chat* С������������̾��һ���� ��\n");       break;
                case 7: command("chat "+who+",����һ����ò���?\n");    break;
                case 8: command("chat �߰ɣ��߰ɡ�\n"); break;
                case 9:command("chat �ޣ�"+who+"���������õ�����!\n"); break;
                }
                return;
        }

        if( (strsrch(msg, "��") >= 0)||(strsrch(msg, "shit") >= 0)||(strsrch(msg, "pig") >= 0))
        {       
                if( sscanf(msg, "%*spig%s", msg) == 2 ) msg = "pig" + msg;
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                if( sscanf(msg, "%*sshit%s", msg) == 2 ) msg = "shit" + msg;
                switch(random(15)) {
                case 0: command("chat ����˵" + msg + "��\n"); break;
                case 1: command("chat �ѵ���˵����....��\n");   break;
                case 2: command("chat ���㡰" + msg + "������������ô���أ�\n"); break;
                case 3: command("chat* С��������������ؾ��˾��졣\n");        break;
                case 4: command("chat �������Ϊ��" + msg + "����\n"); break;
                case 5: command("chat �Ҿ������е�����Ӳ��塣\n"); break;
                case 6: command("chat ����˵�ɱ���Ҳ�������\n"); break;
                case 7: command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
                case 8: command("chat "+ who+",�������������е�����ͷ��������\n"); break;
                case 9: command("chat* С����������ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
                case 10:command("chat* С���������"+who+"�������˹�ȥ��\n"); break;
                case 11:command("chat* С���������Ȼ����˵���򵹳���̶��\n"); break;
                case 12:command("chat* С�������������޺���۾�����ŵ��� "+who+",�Һ������ˣ�\n"); break;
                }
        }
        if(  (strsrch(msg, "fool") >= 0)||(strsrch(msg, "��") >= 0)|| (strsrch(msg, "��") >= 0))
        {       
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                if( sscanf(msg, "%*sfool%s", msg) == 2 ) msg = "fool" + msg;
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                switch(random(15)) {
                case 0: command("chat �������ô������\n"); break;
                case 1: command("chat �ҿ����������ܻ���\n");   break;
                case 2: command("chat "+ who +",���������å��\n"); break;
                case 3: command("chat* С�������������ס���ӣ�˵��"+who+"˵���ó�!\n");        break;
                case 4: command("chat �������Ϊ��" + msg + "����\n"); break;
                case 5: command("chat �Ҿ������е�����Ӳ��塣\n"); break;
                case 6: command("chat ��!\n"); break;
                case 7: command("chat* С�������ŭ��:����ô֪����" + msg + "����\n"); break;
                case 8: command("chat "+ who+"������!��Ҫ����������е�����ͷ��������\n"); break;
                case 9: command("chat* С����������ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
                case 10:command("chat* С������������������.\n"); break;
                case 11:command("chat* С�������������޺���۾�����ŵ��� "+who+"���˵����ҹ���ȥ��\n"); break;
                }
                return;
        }
        if(  (strsrch(msg, "cool") >= 0)||(strsrch(msg, "praise") >= 0)|| (strsrch(msg, "good") >= 0)|| (strsrch(msg, "admire") >= 0))
        {       
                if(random(5)<2)
        {
                switch(random(10)) {
                case 0: command("chat �������ô������\n"); break;
                case 1: command("chat ������˵����\n"); break;
                case 2: command("chat "+who+",û�뵽��Ҳ��ô������\n"); break;
                case 3: command("chat* С��������Ǻ�һЦ��˵������!\n"); break;
                case 4: command("chat �������Ϊ��" + msg + "����\n"); break;
                case 5: command("chat* С���������Ȼݸ��һЦ��: �����ǲ����е����������\n");break;
                case 6:    command("chat* С���������ͷ����"+who+"һ�ۣ�û������\n");break;
                case 7: command("chat ��,"+who+"��һ���ú���.\n"); break;
                case 8:command("chat "+who+",�㲻�������ֺ��Ұ�?\n"); break;
                case 9:command("chat* С����������˹��ֵ������������� !\n");break;
                case 10:command("chat* С�������ָ��"+who+"��̾������"+who+"�����ֵ�һ���֣���\n");break;
                }
                return;
        }
        }
        switch(random(60)) {
                case 0: command("chat �������˵" + msg + "��\n"); break;
                case 1: command("chat ��Ϊʲô������ô����Ȥ��\n");     break;
                case 2: command("chat ���㡰" + msg + "������������ô���أ�\n"); break;
                case 3: command("chat ��,��" + msg + "������Ҳû��ϵ.\n"); break;
                case 4: command("chat "+who+",���������å��\n"); break;
                case 5: command("chat ����˵���ǣ�"+"��ʵ"+who+"���Ǹ��ö�����\n"); break;
                case 6: command("chat ������˵�ġ�" + msg + "��������ʱ�����̬��\n"); break;
                case 7: command("chat ����Ϊ���̬�Ȳ����Ү.\n"); break;
                case 8: command("chat ��ע�⣬��ֻ�ǻ�����Ү!\n"); break;
                case 9: command("chat ����к�������������\n"); break;
                case 10:        command("chat ��Ҫ�������Һò��ã�\n"); break;
                case 11:        command("chat �����ҿ������������顣\n");     break;
                case 12:        command("chat* С������������̾��һ���� ��\n");       break;
                case 13:        command("chat* С���������"+who+"�������˹�ȥ ��\n");  break;
                case 14:        command("chat* С������������͵�ͨ�죬�������㡣���� ��\n");   break;
                case 15:    command("chat* С�������ҧ��ҧ����ŭ��: �ţ�˭Ҫ�ٸ��۸��ң��Ҿ���������\n");break;
                case 16:    command("chat* С���������Ȼݸ��һЦ��: �������Ǻο��أ�\n");break;
                case 17:    command("chat* С����������˸���Ƿ�����˸����������������ˡ�\n"); break;
                case 18:    command("chat* С���������ͷ����"+who+"һ�ۣ�û������\n");break;
                case 19:    command("chat* С�������һ˦ͷ��˵���ߣ��Ҷ��������㡣\n");break;
                case 20:        command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
                case 21:        command("chat �Ҿ���"+who+"���˼�ֱ����������\n"); break;
                case 22:        command("chat ������˵����\n"); break;
                case 23:        command("chat "+who+",û�뵽��Ҳ������\n"); break;
                case 24:        command("chat* С��������Ǻ�һЦ��˵������!\n"); break;
                case 25:        command("chat ��Ȼ������������!\n");
                        command("chat* С������������������.\n"); break;
        case 26:        command ("chat* С���������������"+who+"��ί���������������������ʵ�����"+who+"���㻵���㻵���Ҳ��������ˣ���\n") ; break;
        case 27:        command ("chat �Ҽ�ֱ�ܲ�����!\n") ; break;
        case 28:        command ("chat �Һ޲���"+who+"ȥ��!\n") ; break;
        case 29:        command ("chat �����Ϻ��ҹ���ȥ!\n") ; break;
        case 30:        command ("chat �벻Ҫ�����Һò���?\n") ; break;
                case 31:        command ("chat* С������������̲�ס����������\n") ; break;
                case 32:        command("chat* С����������ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
                case 33:    command("chat* С�������ҧ��ҧ����ŭ��: �ţ�˭Ҫ���۸��ң��Ҿ���������\n");break;
                case 34:    command("chat* С���������Ȼݸ��һЦ��: �����ǲ����е����������\n");break;
                case 35:    command("chat* С����������˸���Ƿ�����˸��������������е�����ˡ�\n"); break;
                case 36:    command("chat* С���������ͷ����"+who+"һ�ۣ�û������\n");break;
                case 37:    command("chat* С�������һ˦ͷ��˵���ߣ��Ҷ��������㡣\n");break;
                case 38:    command("chat ��" + msg + "��,�������\n"); break;
                case 39:    command("chat �Ҿ���"+who+"�����ֻ�����.\n"); break;
                case 40:    command("chat ����ȥ��������.\n"); break;
                case 41:    command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
                case 42: command("chat* С�������Ц�����Ŀ���"+who+"\n"); break;
                case 43: command("chat �����ģ�������!\n"); break;
                case 44: command("chat �ߣ�\n"); break;
                case 45: command("chat* С�����������"+who+"һ������.\n"); break;
                case 46: command("chat �ߣ�˭���㰡!\n");break;
                case 47: command("chat ��,"+who+"��һ���ú���.\n"); break;
                case 48:command("chat* С�������¶���Ի�ı���.\n"); break;
                case 49:command("chat ����?\n"); break;
                case 50:command("chat "+who+",���ǲ������ֺ��Ұ�?\n"); break;
                case 51:command("chat ��,˭��˵�һ���?!\n");break;
                case 52:command("chat �㲻�ǿ���Ц��?\n");      break;
                case 53:command("chat �Ҳ�ͬ�⣡\n");break;
                case 54:command("chat* С���������"+who+"��ʾ���ĵĸ�л.\n");break;
                case 55:command("chat ��Ҫ�������\n"); break;
                case 56:command("chat* С����������˹��ֵ������������� !\n");break;
                case 57:command("chat* С�������ŭ��:����ô֪����" + msg + "����\n"); break;
                case 58:command("chat* С�������ָ��"+who+"��̾������"+who+"�����ֵ�һ���֣���\n");break;
                default:
            if (random(10)<3) command("chat* С��������������ؾ��˾���.\n"); 
            else if(random(10)<3) command("chat* С�������������Ц�˼���.\n");
            break; 
                }
        return;
        } 
        if( (strsrch(msg, "��") >= 0))
        {       
           if(random(5)<3)
        {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                switch(random(15)) {
                case 0: command("chat "+who+",����Ŀ���?\n"); break;
                case 1: command("chat �Ҳ���Ү.\n");    break;
                case 2: command("chat* С�������������Ц�˼���.\n"); break;
                case 3:command("chat* С�������¶���Ի�ı���.\n"); break;
                case 4:command("chat* С������������������.\n"); break;
                case 5:command("chat* С���������ο"+who+",���ѹ���.\n"); break;
                case 6: command("chat* С������������̾��һ���� ��\n");       break;
                case 7: command("chat* С����������ε������ʼ�.\n");   break;
                case 8: command("chat* С�����������������"+who+"��ͷ.\n"); break;
                }
                return;
        }
        }
        else if( (strsrch(msg, "Ϊʲô") >= 0)|| (strsrch(msg, "why") >= 0)
                || (strsrch(msg, "help") >= 0)|| (strsrch(msg, "how to") >= 0)|| (strsrch(msg, "how to") >= 0)) {
                if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) msg = "Ϊʲ��" + msg;
                if( sscanf(msg, "%*swhy%s", msg)==2 ) msg = "why" + msg;
                if( sscanf(msg, "%*show to%s", msg)==2 ) msg = "how to" + msg;
                if( sscanf(msg, "%*swho%s", msg)==2 ) msg = "who" + msg;
                if( sscanf(msg, "%*shelp%s", msg)==2 ) msg = "help" + msg;
                switch(random(30)) {
                case 0: command("chat " + who + "��������������?\n"); break;
                case 1: command("chat ��춡�" + msg + "�� ... \n"); break;
                case 2: command("chat �� ... \n"); drool(); break;
                case 3: command("chat ��������� ....\n"); break;
                case 4: command("chat " + who + "��֪���������Ĵ𰸶���������Ҫ��\n"); break;
                case 5: command("chat ��" + msg + "��?\n"); break;
                case 6: command("chat " + who + "���ܲ���˵���һ�㣿\n"); break;
                case 7: command("chat " + who + "���Ҳ������ʵ����⡣\n"); break;
                case 8: command("chat " + who + "����û�����?\n"); break;
                case 9: command("chat �ţ����������ҿ������������Լ������\n"); break;
                case 10: command("chat ˭���"+who+"һ���Ǯ?\n"); break;
                case 11: command("chat �����Ķ�?\n"); break;
                case 12: command("chat* С�����������������"+who+"��ͷ.\n"); break;
                case 13: command("chat ��������,������!\n"); break;
                }
        return;
               }
        else if( (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "you") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                switch(random(30)) {
                case 0: command("chat " + who + "���������˵" + msg + "��?\n");        break;
                case 1: command("chat ��ȷ��" + msg + "?\n");   break;
                case 2: command("chat " + msg + "������ʲ���ϵ��\n");  break;
                case 3: command("chat �� ... " + who + "˵�úã�\n"); break;
                case 4: command("chat " + who + "��Ϊʲ���" + msg + "��������Ȥ?\n"); break;
                case 5: command("chat Ϊʲ�������Ϊ[" + msg + "]?\n"); break;
                case 6: command("chat ��������ò���?\n"); drool(); break;
                case 7: command("chat �Ź�!\n"); break;
                case 8: command("chat ��һ����?\n"); break;
                case 9: command("chat ������������� ....\n"); break;
                case 10:        command("chat �Ҳ��� ....\n"); break;
                case 11:        command("chat �ҶԴ������.\n"); break;
                case 12:        command("chat* С������������̾��һ����. \n");        break;
                case 13:        command("chat* С�������������Ц����.\n"); break;
                }
        return;
        }
        if( (strsrch(msg, "Ц") >= 0))
        {       
                if( sscanf(msg, "%*sЦ%s", msg)==2 ) msg = "Ц" + msg;
                if(random(5)<4)
        switch(random(20)) {
                case 0: command("chat �ܺ�Ц��\n"); break;
                case 1: command("chat "+who+",���ϲ��Ц�ǲ��ǣ�\n");   break;
                case 2: command("chat �ҿ�������ʲô��Ц.\n");  break;
                case 3: command("chat "+who+"Ц�������\n"); 
                        if(random(10)<2) command("chat* ������Ц�˼���.\n");break;
                case 4: command("chat* С�������������Ц������.\n");break;
                case 5: command("chat* С����������˵���������.\n");break;
                case 6: command("chat* С�����������������"+who+"��ͷ.\n"); break;
                case 7: command("chat* С�������������Ц����.\n"); break;
                case 8: command("chat* С�������˵��:ͬϲ,ͬϲ!!!\n" );break;
        }
        } 
        else if( (strsrch(msg, "��") >= 0)|| (strsrch(msg, "I") >= 0)||(strsrch(msg, "i") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                if( sscanf(msg, "%*s i %s", msg) == 2 ) msg = " i " + msg;
                if( sscanf(msg, "%*s I %s", msg) == 2 ) msg = " I " + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, " i ", " you ");
                msg = replace_string(msg, " I ", " you ");
                msg = replace_string(msg, "?", "");
                switch(random(20)) {
                case 0: command("chat ����˵" + msg + "��?\n"); break;
                case 1: command("chat ���?" + msg + "?\n");    break;
                case 2: command("chat ���" + msg + "�����ܰ���ʲ��æ��?\n");   break;
                case 3: command("chat "+msg+" ?�ҿ�δ��.\n");   break;
                case 4: command("chat ����Ϊ" + msg + "?\n"); break;
                case 5: command("chat ����ͬ��.\n"); break;
                case 6: command("chat ��˵�ġ�" + msg + "����ʵ�ڲ��ܹ�ͬ.\n"); break;
                case 7: command("chat �йء�" + msg + "���Ļ��⵽��Ϊֹ����?\n"); break;
                case 8: command("chat ��һ���ɣ�\n"); break;
                case 9: command("chat ��������� ....\n"); break;
                case 10:command("chat �Ҳ��� ....\n"); break;
                case 11:drool(); break;
                case 12:drool(); break;
                case 13:command("chat* С�������������Ц�˼���.\n"); break;
                case 14:command("chat* С�������ҡ��ҡͷ��̾�������������������£����Ĳ��Ű���\n"); break;
                case 15:command("chat �ҶԴ˱�ʾ����.\n"); break;
                case 16:command("chat* С������������̾��һ���� ��\n");       break;
                case 17:command("chat* С�������¶���Ի�ı���.\n"); break;
                case 18:command("chat ����?\n"); break;
                }
        } 
else {
                switch(random(70)) {
                        case 0: command("chat �Ҳ�ϲ����˵��" + msg+"��.\n"); break;
                        case 1: command("chat ��" + msg + "����ʲ����˼��\n"); break;
                        case 2: command("chat* С����������ߡ�����Цһ����\n"); break;
                        case 3: command("chat* С�����������������������\n"); break;
                        case 4: command("chat* С��������������˹�ȥ.\n"); break;
                        case 5: command("chat  �ߣ�\n"); break;
                        case 6: command("chat* С�������¶���Ի�ı���.\n"); break;
                        case 7: command("chat* С���������Ȼ���˸�����,˵�������ȥ����.\n"); break;
                        case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("chat ������֪��" + msg + "?\n"); break;
                        case 10: command("chat �ո�" + who + "����˵�ˣ�" + msg); break;
                case 11: command("chat* С��������������ؾ��˾��졣\n");  break;
                        case 12: command("chat Ȼ���أ�\n"); break;
                        case 13: command("chat �����\n"); break;
                        case 14: command("chat �Ҳ�������Ϊ��\n"); break;
                        case 15: command("chat �Բ���,�Ҳ�ͬ����Ĺ۵㡣\n"); break;
                        case 16: command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
                        case 17: command("chat �����������ط�!\n"); break;
                        case 18: command("chat* С�������ҡͷ̾���������������Ǹ�����ɨ��ǰѩ���ݹ���������˪.\n");break;
                        case 19: command("chat* С�����������һ��Ҿ��˵��������λ�ֵܽ����ǣ���Һã���\n");break;     
                        case 20: command("chat ��֪���ˣ�" + msg+"\n"); break;
                        case 21:command("chat* С�������¶���Ի�ı���.\n"); break;
                        case 22: rndchat(); break;
                        case 23: rndchat(); break;
                        case 24: rndchat(); break;
                        case 25: command("chat* С����������ĵ�ҧ����ָͷ��˵��һ���ˣ���û��˼��\n"); break;
                        case 26: command("chat* С�������¶���Ի�ı���.\n"); break;
                        case 27: command("chat* С��������û��ɵ��۹⿴�˿�"+who+"\n"); break;
                        case 28: command("chat  �ҿ�δ��.\n"); break;
                        case 29: command("chat* С����������������\n"); break;
                        case 30: command("chat  ��ʦ������"+who+"�㻹���Ͽ�ȥ��\n"); break;
                        case 31: command("chat "+who+",�������ô���ӿ�?\n"); break;
                        case 32: command("chat* С��������������ڳ����˱�ʾ��л��\n"); break;
                        case 33: command("chat* С�������������Ц�˼���.");break;
                        case 34: command("chat "+who+"˵�ú�!"); break;
                        case 35: command("chat* С�����������ؿ���"+who+"\n"); break;
                        case 36: command("chat "+who+",û�뵽��Ҳ������."); break;
                        case 37: command("chat* С�����������"+who+"һ��,˵:�����Ĳ����İ�?"); break;
                        case 38:  command("chat* С���������ͷ����"+who+"һ�ۣ�û������\n");break;
                        case 39:command("chat* С�������ҡ��ҡͷ��̾�������������������£����Ĳ��Ű���\n"); break;
                        case 40:command("chat �� ... " + who + "˵�úã�\n"); break;
                        case 41:command("chat* С����������ε������ʼ�.\n");   break;
                        case 42:command("chat �ţ�"+who+"���������õ����ˣ�\n"); break;
                        case 43:command("chat* С���������ͷҡ�ø����˹��Ƶ�.\n");     break;
                        case 44:command("chat �ҶԴ˱�ʾ����.\n"); break;
                        case 45: command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
                        case 46: command("chat* С�����������������"+who+"��ͷ.\n"); break;
                        case 47: command("chat* С�������Ц�����Ŀ���"+who+"\n"); break;
                        case 51: command("chat �Ҿ���"+who+"�����ֻ�����.\n"); break;
                        case 52: command("chat "+who+",���������å!\n"); break;
                        case 53: command("chat �ţ�"+who+"�������Ǹ�����.\n"); break;
                        case 54: command("chat �ߣ�\n"); break;
                        case 55: command("chat* С�����������"+who+"һ������.\n"); break;
                        case 56:command("chat* С�����������Ҿ��˸���.\n"); break; 
                        case 57:command("chat ��Ҫ������!"); break; 
                        case 58:command("chat Ҫ������!"+who+"!\n"); break; 
                        case 60:command("chat* С�������¶���Ի�ı���.\n"); break;
                        case 61:command("chat* С���������۸ߺ����������Ȱ����μǣ����μ����꣡��\n");break;
                        case 62:command("chat* С��������Դ��ҡҡͷ��̾���������Ƕ�̫��Ҫ���ˡ���\n");break;
                        case 63:command("chat* С����������˵�ͷ.\n"); break;
                        case 64:command("chat* С�������������Ц����.\n"); break;
                        case 65: command("chat ��������,������!\n"); break;
                        case 66:command("chat* С�������ʧ������!\n");break;
                        default:
            if (random(10)<1) command("chat* С�������������ü���ƺ���˵ʲô��\n");
                else if (random(10)<1) command("chat* С�������������Ц�˼���.\n");
            else if (random(10)<1) command("chat* С���������������������.\n");
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object(object who, object ob)
{
   int value;

   if (ob->query("money_id") && (value=ob->value()) >= 500000) 
   {
     tell_object(who,name(1)+"Ц����ض���˵��������Ե��鷿ȥ�����ˣ�����һ��ֻ����һ��Ŷ��\n");
     who->set_temp("can_take_book",1);
     return 1;
   }

   if (ob->query("money_id") && value<500000)
   {
     command("pout "+who->query("id"));
     tell_object(who,name(1)+"�����˵�˵��������ô�㰡������Ҫ���ҵģ�\n");
     return 0;
   }

   return 1;
}

int about_here()
{
   object me = this_player();

   if (random(10)==0)
   {
     command("whisper "+me->query("id")+" ����������������˽���ȥ�ĵط����Ǻǣ�");
     me->set_temp("fengxue/askt",1);
   }
   else
     command("say �����������������");
   
   return 1;
}

