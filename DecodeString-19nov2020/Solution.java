class Solution { // doesntwork
    
    public String decodeString(String s) {
        String decoded = "";
        for (int i = 0; i < s.length(); i++) {
            int k = 1;
            char c = s.charAt(i);
            switch (c) {
                case '2':
                    k = 2;
                    break;
                case '3':
                    k = 3;
                    break;
                case '4':
                    k = 4;
                    break;
                case '5':
                    k = 5;
                    break;
                case '6':
                    k = 6;
                    break;
                case '7':
                    k = 7;
                    break;
                case '8':
                    k = 8;
                    break;
                case '9':
                    k = 2;
                    break;
                default:
                    k = 0;
            }
            if (k == 0) {
                decoded += c;
                continue;
            }
            i++;
            char c = s.charAt(i);
            switch (c) {
                case '0':
                    k = k*10;
                    break;
                case '1':
                    k = k*10 + 1;
                    break;
                case '2':
                    k = k*10 + 2;
                    break;
                case '3':
                    k = k*10 + 3;
                    break;
                case '4':
                    k = k*10 + 4;
                    break;
                case '5':
                    k = k*10 + 5;
                    break;
                case '6':
                    k = k*10 + 6;
                    break;
                case '7':
                    k = k*10 + 7;
                    break;
                case '8':
                    k = k*10 + 8;
                    break;
                case '9':
                    k = k*10 + 9;
                    break;
                default:
                    int i2 = i+1;
                    for (int count = 0; count < k; count++) {
                        i2 = i+1;
                        char c2 =s.charAt(i2);
                        while (c2 != "]") {
                            decoded += c2;
                            c2 =s.charAt(++i2);
                        }
                    }
                    i = i2+1;
                }
                if (k < 10) {
                    continue;
                }
                i++;
                char c = s.charAt(i);
                switch (c) {
                    case '0':
                        k = k*10;
                        break;
                    case '1':
                        k = k*10 + 1;
                        break;
                    case '2':
                        k = k*10 + 2;
                        break;
                    case '3':
                        k = k*10 + 3;
                        break;
                    case '4':
                        k = k*10 + 4;
                        break;
                    case '5':
                        k = k*10 + 5;
                        break;
                    case '6':
                        k = k*10 + 6;
                        break;
                    case '7':
                        k = k*10 + 7;
                        break;
                    case '8':
                        k = k*10 + 8;
                        break;
                    case '9':
                        k = k*10 + 9;
                        break;
                    default:
                        i++;
                        c =s.charAt(i);
                        int i2 = i+1;
                        for (int count = 0; count < k; count++) {
                            i2 = i+1;
                            char c2 = c;
                            while (c2 != "]") {
                                decoded += c2;
                                c2 =s.charAt(++i2);
                            }
                        }
                        i = i2+1;
                }
            }
        return decoded;
    }
}
