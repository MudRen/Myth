void relay_channel(object ob, string channel, string msg) {
        string who;
        if( !userp(ob) || (channel != "rumor") ) return;
      if (wizardp(ob)) return;
        who = ob->query("name");
        if( ob==this_object() ) return;
        message_vision(who+" says:"+msg+"\n");
        if (!random(4)) {
          remove_call_out("reveal");
          call_out("reveal",1,ob);
        }
}
void reveal(object who) {
  string name=who->query("name"),id=who->query("id");
  switch (random(5)) {
   case 0: command("rumor* ĳ�˶�ݺݵ���в����"+name+"�����"+RANK_D->query_rude(who)+"�����ұ��죡");break;
    case 1: command("rumor* ĳ����"+name+"ҡҡʳָ����С���ѣ�����������ร���");break;  
     case 2: command("say "+name+"��"+RANK_D->query_rude(who)+"������ҥ�ˡ�");break;
     case 3: command("say "+name+"��ô��ôϲ����ҥѽ��");break;
     case 4: command("rumor* ĳ�˿Ϳ������ض�"+name+"�����ǲ���������ҥ������ǵĻ�������������ˡ�");break;
  }
}
