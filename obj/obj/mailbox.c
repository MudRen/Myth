inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
        set_name("����", ({ "mailbox", "box" }) );
        set("long",
                "����һ���������š����ŵ����䣬�����������ָ������������ʼ���\n\n"
                "mail <ĳ��>               ���Ÿ����ˡ�\n"
                "forward <�ż����> <ĳ��> ��ĳ����ת�ĸ����ˡ�\n"
                "from                      �鿴�����е��ż���\n"
                "read <�ż����>           �Ķ�һ���ż���\n"
                "readmail <�ż����>       �Ķ�һ���ż���\n"
                "discard <�ż����>        ����һ���ż���\n"
                "dismail <�ż����>        ����һ���ż���\n"
                "��������԰��ͻ������readmail���Ķ��ż���\n"
        );
        set("unit", "��");
        set("no_drop", 1);
        set("no_give", 1);
        set("no_insert", 1);

        seteuid(getuid());
}

void set_owner(string id)
{
        set("owner_id", id);
        mails=({});
        restore();
        //reset some properties because some mailboxes
        //are restored from old save file.
        //mon 2/22/98
        set("long",
                "����һ���������š����ŵ����䣬�����������ָ������������ʼ���\n\n"
                "mail <ĳ��>               ���Ÿ����ˡ�\n"
                "forward <�ż����> <ĳ��> ��ĳ����ת�ĸ����ˡ�\n"
                "from                      �鿴�����е��ż���\n"
                "read <�ż����>           �Ķ�һ���ż���\n"
                "readmail <�ż����>       �Ķ�һ���ż���\n"
                "discard <�ż����>        ����һ���ż���\n"
                "dismail <�ż����>        ����һ���ż���\n"
                "��������԰��ͻ������readmail���Ķ��ż���\n"
        );
        set("no_drop", 1);
        set("no_give", 1);
}

void init()
{
        object ob;

        if( this_player() && environment()==this_player() ) {
                set_owner( (string)this_player()->query("id") );
                this_player()->set_temp("mbox_ob", this_object());
                set_name( this_player()->name(1) + "������", ({ "mailbox", "box" }) );
                add_action("do_mail", "mail");
                add_action("do_forward", "forward");
                add_action("do_from", "from");
                add_action("do_read", "read");
                add_action("do_read", "readmail");
                add_action("do_discard", "discard");
                add_action("do_discard", "dismail");
        }
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{      
        if( !pointerp(mails) ) mails = ({ mail });
        else mails += ({ mail });
        save();
}

void send_mail(string rcvr, mapping mail, int silent)
{
        object ppl, ob, mbx;

        // Acquire the login object of receiver and mark the arrival of newmail.
        ob = FINGER_D->acquire_login_ob(rcvr);
        if( !ob ) {
                write("û������˴��ڡ�\n");
                return;
        }
        ob->add("new_mail", 1);
        ob->save();

        // Get the mailbox or make a new one if not found.
        ppl = find_player(rcvr);
        if(ppl && this_player()->visible(ppl)) {
            mbx = ppl->query_temp("mbox_ob");
            if(!silent)
              write("\n����ǧ����֪ͨ " + rcvr + " ����!\n");
            tell_object(ppl, "ǧ���۸���˵���������ţ�����һ�£�\n\n");
        } 
        if( !mbx ) {
                mbx = new(MAILBOX_OB);
                mbx->set_owner(rcvr);
        }

        // Receive the mail and destruct the objects if receiver is off-line.
        mbx->receive_mail(mail);
        if(!ppl) {
                destruct(mbx);
                destruct(ob);
        }
}

int do_mail(string arg)
{
        mapping mail;

        if( this_player()!=environment() ) return 0;

        if( !arg || arg=="" )
                return notify_fail("��Ҫ���Ÿ�˭��\n");

      if( time()-this_player()->query("lastmail")<20) 
                return notify_fail("���ʹ�ù�����,�Ȼ����!!\n");
        mail = ([
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
                "title": "����",
                "to": arg,
                "time": time(),
                "status": "N",
                "text": ""
        ]);
        write("�ż����⣺");
        input_to("get_mail_title", mail);
        return 1;
}

void get_mail_title(string str, mapping mail)
{
    // mon 6/16/98
    str=CONVERT_D->input(str, this_player());

        if( str!="" ) mail["title"] = str;
        write("�ż����ݣ�\n");
        this_player()->edit( (: get_mail_text, mail :) );
       this_player()->set("lastmail",time());
}

void get_mail_text(mapping mail, string str)
{
        mail["text"] = str;
        write("���Լ�Ҫ��һ�ݱ�����(y/n)��[n]");
        input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
        if( yn[0]=='y' || yn[0]=='Y' ) {
          receive_mail(mail);
        }
        send_mail(mail["to"], mail,0);
        write("Ok.\n");
}

int do_from()
{
        int i;

      if( time()-this_player()->query("lastreadmail")<10) 
                return notify_fail("���ʹ�ù�����,�Ȼ����!!\n");
        this_player()->set("lastreadmail",time());
        if( !pointerp(mails) || !sizeof(mails) ) {
                write("���������Ŀǰû���κ��ż���\n");
                return 1;
        }
        write("������������ڹ��� " + sizeof(mails) + " ���ż���\n\n");
        for(i=0; i<sizeof(mails); i++)
                printf("%1s %-3d %-40s From: %-20s\n",
                  (mails[i]["status"]=="N"?"N":" "),
                  i+1, mails[i]["title"], mails[i]["from"] );
        write("\n");
        return 1;
}

int do_read(string arg)
{
        int num;
        string str;

      if( time()-this_player()->query("lastreadmail")<10) 
                return notify_fail("���ʹ�ù�����,�Ȼ����!!\n");
                
        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ����һ���ţ�\n");

        if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        str=sprintf("�ż���ţ�%d\n�ż����⣺%s\n����ʱ�䣺%s"+
                "\n�� �� �ˣ�%s\n�� �� �ˣ�%s\n\n%s\n",
                num+1, mails[num]["title"], ctime(mails[num]["time"]),
                mails[num]["from"], mails[num]["to"], mails[num]["text"] );
        this_player()->start_more(str);
        this_player()->set("lastreadmail",time());
        mails[num]["status"]="O";
        save();

        return 1;
}

int do_discard(string arg)
{
        int num;

      if( time()-this_player()->query("lastreadmail")<10) 
                return notify_fail("���ʹ�ù�����,�Ȼ����!!\n");
        this_player()->set("lastreadmail",time());
        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ������һ���ţ�\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        if (num!=0)
           if (num==sizeof(mails)-1)
             mails = mails[0..num-1];
           else
             mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
        else
           mails = mails[num+1..sizeof(mails)-1];
        save();
        write("Ok.\n");

        return 1;
}

int do_forward(string arg)
{
        string dest;
        int num;
        mapping m;

        if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
                return notify_fail("��Ҫ����һ����ת�ĸ����ˣ�\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");
      if( time()-this_player()->query("lastmail")<60) 
               return notify_fail("���ʹ�ù�����,�Ȼ����!!\n");

        num --;

        m = ([]);
        m["title"] = mails[num]["title"];
        m["text"] = mails[num]["text"];
        m["time"] = mails[num]["time"];
        m["from"] = mails[num]["from"] + "/ת����" + this_player()->query("name");
        m["to"] = dest;
        m["status"] = "N";
        send_mail( dest, m ,0);
        write("Ok.\n");
      this_player()->set("lastmail",time());

        return 1;
}

void owner_is_killed() { destruct(this_object()); }

int query_new_mail()
{
    int num=0,i;
    if (!pointerp(mails)||!sizeof(mails)) 
       return num;
    for (i=0;i<sizeof(mails);i++)
       if (mails[i]["status"]=="N") num++;
    return num;
}
